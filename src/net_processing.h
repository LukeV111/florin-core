// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
//
// File contains modifications by: The Gulden developers
// All modifications:
// Copyright (c) 2018 The Gulden developers
// Authored by: Willem de Jonge (willem@isnapp.nl)
// Distributed under the GULDEN software license, see the accompanying
// file COPYING

#ifndef NET_PROCESSING_H
#define NET_PROCESSING_H

#include "net.h"
#include "validation/validationinterface.h"

/** Default for -maxorphantx, maximum number of orphan transactions kept in memory */
static const unsigned int DEFAULT_MAX_ORPHAN_TRANSACTIONS = 100;
/** Expiration time for orphan transactions in seconds */
static const int64_t ORPHAN_TX_EXPIRE_TIME = 20 * 60;
/** Minimum time between orphan transactions expire time checks in seconds */
static const int64_t ORPHAN_TX_EXPIRE_INTERVAL = 5 * 60;
/** Default number of orphan+recently-replaced txn to keep around for block reconstruction */
static const unsigned int DEFAULT_BLOCK_RECONSTRUCTION_EXTRA_TXN = 100;
/** Timeout for the header request/response cycle during synchronisation
 * This time can and should be quite tight as we want to quickly drop peers that are not very responsive
 * Because of the tight timeout care shuld be taken that only "external" time is measured, ie.
 * the timeout should be reset as soon as an incoming header is known to be the response, not after fully processing
 * it which might take considerable time on some platforms. The timeout should be set again as soon as a new header
 * request message is pushed out.
 */
#define HEADERS_DOWNLOAD_RESPONSE_TIMEOUT (Params().IsRegtestLegacy() ? 700 * 1000000 : 7 * 1000000) // 7 seconds

/** When most recent header is newer, then block download is allowed when using SPV
 * (and automatic block requests is enabled). */
static constexpr int64_t HEADERS_RECENT_FOR_BLOCKDOWNLOAD = 24 * 3600; // a day

/** Register with a network node to receive its signals */
void RegisterNodeSignals(CNodeSignals& nodeSignals);
/** Unregister a network node */
void UnregisterNodeSignals(CNodeSignals& nodeSignals);

class PeerLogicValidation : public CValidationInterface {
private:
    CConnman* connman;

public:
    PeerLogicValidation(CConnman* connmanIn);

    void BlockConnected(const std::shared_ptr<const CBlock>& pblock, const CBlockIndex* pindexConnected, const std::vector<CTransactionRef>& vtxConflicted) override;
    void UpdatedBlockTip(const CBlockIndex *pindexNew, const CBlockIndex *pindexFork, bool fInitialDownload) override;
    void BlockChecked(const CBlock& block, const CValidationState& state) override;
    void NewPoWValidBlock(const CBlockIndex *pindex, const std::shared_ptr<const CBlock>& pblock) override;
};

struct CNodeStateStats {
    int nMisbehavior;
    int nSyncHeight;
    int nCommonHeight;
    std::vector<int> vHeightInFlight;
};

/** Get statistics from node state */
bool GetNodeStateStats(NodeId nodeid, CNodeStateStats &stats);
/** Increase a node's misbehavior score. */
void Misbehaving(NodeId nodeid, int howmuch);

/** Process protocol messages received from a given node */
bool ProcessMessages(CNode* pfrom, CConnman& connman, const std::atomic<bool>& interrupt);
/**
 * Send queued protocol messages to be sent to a give node.
 *
 * @param[in]   pto             The node which we are sending messages to.
 * @param[in]   connman         The connection manager for that node.
 * @param[in]   interrupt       Interrupt condition for processing threads
 * @return                      True if there is more work to be done
 */
bool SendMessages(CNode* pto, CConnman& connman, const std::atomic<bool>& interrupt);

void PreventBlockDownloadDuringHeaderSync(bool state);

/**
 * Prioritize a block for downloading
 * Blocks requested with priority will be downloaded and processed first
 * Priority requests are delivered in requested order
 * Downloaded blocks will not trigger ActivateBestChain
 */
typedef std::function<void(const std::shared_ptr<const CBlock>, const CBlockIndex*)> PriorityDownloadCallback_t;
void AddPriorityDownload(const std::vector<const CBlockIndex*>& blocksToDownload, const PriorityDownloadCallback_t& callback);
void CancelPriorityDownload(const CBlockIndex* index, const PriorityDownloadCallback_t& callback);
void CancelAllPriorityDownloads();
size_t CountPriorityDownloads();

int GetProbableHeight();

#endif
