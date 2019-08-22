/*
 * Argon2 reference source code package - reference C implementations
 *
 * Copyright 2015
 * Daniel Dinu, Dmitry Khovratovich, Jean-Philippe Aumasson, and Samuel Neves
 *
 * You may use this work under the terms of a Creative Commons CC0 1.0
 * License/Waiver or the Apache Public License 2.0, at your option. The terms of
 * these licenses can be found at:
 *
 * - CC0 1.0 Universal : http://creativecommons.org/publicdomain/zero/1.0
 * - Apache 2.0        : http://www.apache.org/licenses/LICENSE-2.0
 *
 * You should have received a copy of both of these licenses along with this
 * software. If not, they may be obtained at the above URLs.
 */
// File contains modifications by: The Gulden developers
// All modifications:
// Copyright (c) 2019 The Gulden developers
// Authored by: Malcolm MacLeod (mmacleod@gmx.com)
// Distributed under the GULDEN software license, see the accompanying
// file COPYING

#include <compat/arch.h>
#ifdef ARCH_CPU_X86_FAMILY // Only x86 family CPUs have AVX2

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "argon_echo.h"
#include "core.h"

#include "blake2/blake2.h"
#include "blake2/blamka-round-opt_avx2.h"

#include "compat.h"

#ifndef __clang__
#pragma GCC push_options
#pragma GCC target("avx2")
#else
#pragma clang attribute push (__attribute__((target("avx2"))), apply_to=any(function))
#endif

/*
 * Function fills a new memory block and optionally XORs the old block over the new one.
 * Memory must be initialized.
 * @param state Pointer to the just produced block. Content will be updated(!)
 * @param ref_block Pointer to the reference block
 * @param next_block Pointer to the block to be XORed over. May coincide with @ref_block
 * @param with_xor Whether to XOR into the new block (1) or just overwrite (0)
 * @pre all block pointers must be valid
 */
static void fill_block_avx2(__m256i *state, const argon2_echo_block *ref_block, argon2_echo_block *next_block, int with_xor)
{
    __m256i block_XY[ARGON2_HWORDS_IN_BLOCK];
    unsigned int i;

    if (with_xor)
    {
        for (i = 0; i < ARGON2_HWORDS_IN_BLOCK; i++)
        {
            state[i] = _mm256_xor_si256(state[i], _mm256_loadu_si256((const __m256i *)ref_block->v + i));
            block_XY[i] = _mm256_xor_si256(state[i], _mm256_loadu_si256((const __m256i *)next_block->v + i));
        }
    }
    else
    {
        for (i = 0; i < ARGON2_HWORDS_IN_BLOCK; i++)
        {
            block_XY[i] = state[i] = _mm256_xor_si256(state[i], _mm256_loadu_si256((const __m256i *)ref_block->v + i));
        }
    }

    for (i = 0; i < 4; ++i)
    {
        BLAKE2_ROUND_AVX2_1(state[8 * i + 0], state[8 * i + 4], state[8 * i + 1], state[8 * i + 5], state[8 * i + 2], state[8 * i + 6], state[8 * i + 3], state[8 * i + 7]);
    }

    for (i = 0; i < 4; ++i)
    {
        BLAKE2_ROUND_AVX2_2(state[ 0 + i], state[ 4 + i], state[ 8 + i], state[12 + i], state[16 + i], state[20 + i], state[24 + i], state[28 + i]);
    }

    for (i = 0; i < ARGON2_HWORDS_IN_BLOCK; i++)
    {
        state[i] = _mm256_xor_si256(state[i], block_XY[i]);
        _mm256_storeu_si256((__m256i *)next_block->v + i, state[i]);
    }
}

static void next_addresses_avx2(argon2_echo_block *address_block, argon2_echo_block *input_block)
{
    /*Temporary zero-initialized blocks*/
    __m256i zero_block[ARGON2_HWORDS_IN_BLOCK];
    __m256i zero2_block[ARGON2_HWORDS_IN_BLOCK];

    memset(zero_block, 0, sizeof(zero_block));
    memset(zero2_block, 0, sizeof(zero2_block));

    /*Increasing index counter*/
    input_block->v[6]++;

    /*First iteration of G*/
    fill_block_avx2(zero_block, input_block, address_block, 0);

    /*Second iteration of G*/
    fill_block_avx2(zero2_block, address_block, address_block, 0);
}



void fill_segment_avx2(const argon2_echo_instance_t *instance, argon2_echo_position_t position)
{
    argon2_echo_block *ref_block = NULL, *curr_block = NULL;
    argon2_echo_block address_block, input_block;
    uint64_t pseudo_rand, ref_index, ref_lane;
    uint32_t prev_offset, curr_offset;
    uint32_t starting_index, i;
    __m256i state[ARGON2_HWORDS_IN_BLOCK];
    
    //Argon2d always has data dependent addressing
    bool data_independent_addressing = false;

    if (instance == NULL)
    {
        return;
    }

    //data_independent_addressing = (instance->type == Argon2_i) || (instance->type == Argon2_id && (position.pass == 0) && (position.slice < ARGON2_SYNC_POINTS / 2));

    if (data_independent_addressing)
    {
        init_block_value(&input_block, 0);

        input_block.v[0] = position.pass;
        input_block.v[1] = position.lane;
        input_block.v[2] = position.slice;
        input_block.v[3] = instance->memory_blocks;
        input_block.v[4] = instance->passes;
        //input_block.v[5] = instance->type;
    }

    starting_index = 0;

    if ((0 == position.pass) && (0 == position.slice))
    {
        starting_index = 2; /* we have already generated the first two blocks */

        /* Don't forget to generate the first block of addresses: */
        if (data_independent_addressing) {
            next_addresses_avx2(&address_block, &input_block);
        }
    }

    /* Offset of the current block */
    curr_offset = position.lane * instance->lane_length + position.slice * instance->segment_length + starting_index;

    if (0 == curr_offset % instance->lane_length)
    {
        /* Last block in this lane */
        prev_offset = curr_offset + instance->lane_length - 1;
    }
    else
    {
        /* Previous block */
        prev_offset = curr_offset - 1;
    }

    memcpy(state, ((instance->memory + prev_offset)->v), ARGON2_BLOCK_SIZE);

    for (i = starting_index; i < instance->segment_length; ++i, ++curr_offset, ++prev_offset)
    {
        /*1.1 Rotating prev_offset if needed */
        if (curr_offset % instance->lane_length == 1)
        {
            prev_offset = curr_offset - 1;
        }

        /* 1.2 Computing the index of the reference block */
        /* 1.2.1 Taking pseudo-random value from the previous block */
        if (data_independent_addressing)
        {
            if (i % ARGON2_ADDRESSES_IN_BLOCK == 0)
            {
                next_addresses_avx2(&address_block, &input_block);
            }
            pseudo_rand = address_block.v[i % ARGON2_ADDRESSES_IN_BLOCK];
        }
        else
        {
            pseudo_rand = instance->memory[prev_offset].v[0];
        }

        /* 1.2.2 Computing the lane of the reference block */
        ref_lane = ((pseudo_rand >> 32)) % instance->lanes;

        if ((position.pass == 0) && (position.slice == 0))
        {
            /* Can not reference other lanes yet */
            ref_lane = position.lane;
        }

        /* 1.2.3 Computing the number of possible reference block within the
         * lane.
         */
        position.index = i;
        ref_index = index_alpha(instance, &position, pseudo_rand & 0xFFFFFFFF, ref_lane == position.lane);

        /* 2 Creating a new block */
        ref_block = instance->memory + instance->lane_length * ref_lane + ref_index;
        curr_block = instance->memory + curr_offset;
        
        
        if(0 == position.pass)
        {
            fill_block_avx2(state, ref_block, curr_block, 0);
        }
        else
        {
            fill_block_avx2(state, ref_block, curr_block, 1);
        }
    }
}

#ifdef __clang__
#pragma clang attribute pop
#else
#pragma GCC pop_options
#endif
#endif
