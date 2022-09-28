// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#pragma once

#include "djinni_support.hpp"
#include "witness_account_statistics_record.hpp"

namespace djinni_generated {

class NativeWitnessAccountStatisticsRecord final {
public:
    using CppType = ::WitnessAccountStatisticsRecord;
    using JniType = jobject;

    using Boxed = NativeWitnessAccountStatisticsRecord;

    ~NativeWitnessAccountStatisticsRecord();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeWitnessAccountStatisticsRecord();
    friend ::djinni::JniClass<NativeWitnessAccountStatisticsRecord>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("unity_wallet/jniunifiedbackend/WitnessAccountStatisticsRecord") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;JJJJJJJJJJJJJIZ)V") };
    const jfieldID field_mRequestStatus { ::djinni::jniGetFieldID(clazz.get(), "mRequestStatus", "Ljava/lang/String;") };
    const jfieldID field_mAccountStatus { ::djinni::jniGetFieldID(clazz.get(), "mAccountStatus", "Ljava/lang/String;") };
    const jfieldID field_mBlocksSinceLastActivity { ::djinni::jniGetFieldID(clazz.get(), "mBlocksSinceLastActivity", "J") };
    const jfieldID field_mAccountWeight { ::djinni::jniGetFieldID(clazz.get(), "mAccountWeight", "J") };
    const jfieldID field_mAccountWeightAtCreation { ::djinni::jniGetFieldID(clazz.get(), "mAccountWeightAtCreation", "J") };
    const jfieldID field_mAccountParts { ::djinni::jniGetFieldID(clazz.get(), "mAccountParts", "J") };
    const jfieldID field_mAccountAmountLocked { ::djinni::jniGetFieldID(clazz.get(), "mAccountAmountLocked", "J") };
    const jfieldID field_mAccountAmountLockedAtCreation { ::djinni::jniGetFieldID(clazz.get(), "mAccountAmountLockedAtCreation", "J") };
    const jfieldID field_mNetworkTipTotalWeight { ::djinni::jniGetFieldID(clazz.get(), "mNetworkTipTotalWeight", "J") };
    const jfieldID field_mNetworkTotalWeightAtCreation { ::djinni::jniGetFieldID(clazz.get(), "mNetworkTotalWeightAtCreation", "J") };
    const jfieldID field_mAccountInitialLockPeriodInBlocks { ::djinni::jniGetFieldID(clazz.get(), "mAccountInitialLockPeriodInBlocks", "J") };
    const jfieldID field_mAccountRemainingLockPeriodInBlocks { ::djinni::jniGetFieldID(clazz.get(), "mAccountRemainingLockPeriodInBlocks", "J") };
    const jfieldID field_mAccountExpectedWitnessPeriodInBlocks { ::djinni::jniGetFieldID(clazz.get(), "mAccountExpectedWitnessPeriodInBlocks", "J") };
    const jfieldID field_mAccountEstimatedWitnessPeriodInBlocks { ::djinni::jniGetFieldID(clazz.get(), "mAccountEstimatedWitnessPeriodInBlocks", "J") };
    const jfieldID field_mAccountInitialLockCreationBlockHeight { ::djinni::jniGetFieldID(clazz.get(), "mAccountInitialLockCreationBlockHeight", "J") };
    const jfieldID field_mCompoundingPercent { ::djinni::jniGetFieldID(clazz.get(), "mCompoundingPercent", "I") };
    const jfieldID field_mIsOptimal { ::djinni::jniGetFieldID(clazz.get(), "mIsOptimal", "Z") };
};

}  // namespace djinni_generated
