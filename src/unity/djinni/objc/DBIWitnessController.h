// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBResultRecord.h"
#import "DBWitnessAccountStatisticsRecord.h"
#import "DBWitnessEstimateInfoRecord.h"
#import "DBWitnessFundingResultRecord.h"
#import <Foundation/Foundation.h>


/** C++ interface to control witness accounts */
@interface DBIWitnessController : NSObject

/** Get information on min/max witness periods, weights etc. */
+ (nonnull NSDictionary<NSString *, NSString *> *)getNetworkLimits;

/** Get an estimate of weights/parts that a witness account will be funded with */
+ (nonnull DBWitnessEstimateInfoRecord *)getEstimatedWeight:(int64_t)amountToLock
                                         lockPeriodInBlocks:(int64_t)lockPeriodInBlocks;

/** Fund a witness account */
+ (nonnull DBWitnessFundingResultRecord *)fundWitnessAccount:(nonnull NSString *)fundingAccountUUID
                                          witnessAccountUUID:(nonnull NSString *)witnessAccountUUID
                                               fundingAmount:(int64_t)fundingAmount
                                 requestedLockPeriodInBlocks:(int64_t)requestedLockPeriodInBlocks;

/** Renew a witness account */
+ (nonnull DBWitnessFundingResultRecord *)renewWitnessAccount:(nonnull NSString *)fundingAccountUUID
                                           witnessAccountUUID:(nonnull NSString *)witnessAccountUUID;

/** Get information on account weight and other witness statistics for account */
+ (nonnull DBWitnessAccountStatisticsRecord *)getAccountWitnessStatistics:(nonnull NSString *)witnessAccountUUID;

/** Turn compounding on/off */
+ (void)setAccountCompounding:(nonnull NSString *)witnessAccountUUID
            percentToCompount:(int32_t)percentToCompount;

/** Check state of compounding; returns a percentage between 1 and 100, or 0 if not compounding */
+ (int32_t)isAccountCompounding:(nonnull NSString *)witnessAccountUUID;

/** Get the witness address of the account */
+ (nonnull NSString *)getWitnessAddress:(nonnull NSString *)witnessAccountUUID;

/** Get the optimal distribution amounts for the account; totalNetworkWeight should be the value of "total_weight_eligible_raw" */
+ (nonnull NSArray<NSNumber *> *)getOptimalWitnessDistribution:(int64_t)amount
                                              durationInBlocks:(int64_t)durationInBlocks
                                            totalNetworkWeight:(int64_t)totalNetworkWeight;

/** Same as the above but calculates all the paramaters from the account UUID; its more efficient to use the other call if you already have these values */
+ (nonnull NSArray<NSNumber *> *)getOptimalWitnessDistributionForAccount:(nonnull NSString *)witnessAccountUUID;

/** Redistribute a witness account to its optimal distribution, call 'getOptimalWitnessDistribution' first to calculate this */
+ (nonnull DBResultRecord *)optimiseWitnessAccount:(nonnull NSString *)witnessAccountUUID
                                fundingAccountUUID:(nonnull NSString *)fundingAccountUUID
                               optimalDistribution:(nonnull NSArray<NSNumber *> *)optimalDistribution;

@end
