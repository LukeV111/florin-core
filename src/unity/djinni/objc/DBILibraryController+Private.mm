// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBILibraryController+Private.h"
#import "DBILibraryController.h"
#import "DBAddressRecord+Private.h"
#import "DBBlockInfoRecord+Private.h"
#import "DBILibraryListener+Private.h"
#import "DBLegacyWalletResult+Private.h"
#import "DBMnemonicRecord+Private.h"
#import "DBMonitorListener+Private.h"
#import "DBMonitorRecord+Private.h"
#import "DBMutationRecord+Private.h"
#import "DBPaymentResultStatus+Private.h"
#import "DBQrCodeRecord+Private.h"
#import "DBTransactionRecord+Private.h"
#import "DBUriRecipient+Private.h"
#import "DBUriRecord+Private.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface DBILibraryController ()

- (id)initWithCpp:(const std::shared_ptr<::ILibraryController>&)cppRef;

@end

@implementation DBILibraryController {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::ILibraryController>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::ILibraryController>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nonnull NSString *)BuildInfo {
    try {
        auto objcpp_result_ = ::ILibraryController::BuildInfo();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (int32_t)InitUnityLib:(nonnull NSString *)dataDir
       staticFilterPath:(nonnull NSString *)staticFilterPath
     staticFilterOffset:(int64_t)staticFilterOffset
     staticFilterLength:(int64_t)staticFilterLength
                testnet:(BOOL)testnet
                spvMode:(BOOL)spvMode
          signalHandler:(nullable id<DBILibraryListener>)signalHandler
              extraArgs:(nonnull NSString *)extraArgs {
    try {
        auto objcpp_result_ = ::ILibraryController::InitUnityLib(::djinni::String::toCpp(dataDir),
                                                                 ::djinni::String::toCpp(staticFilterPath),
                                                                 ::djinni::I64::toCpp(staticFilterOffset),
                                                                 ::djinni::I64::toCpp(staticFilterLength),
                                                                 ::djinni::Bool::toCpp(testnet),
                                                                 ::djinni::Bool::toCpp(spvMode),
                                                                 ::djinni_generated::ILibraryListener::toCpp(signalHandler),
                                                                 ::djinni::String::toCpp(extraArgs));
        return ::djinni::I32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)InitUnityLibThreaded:(nonnull NSString *)dataDir
            staticFilterPath:(nonnull NSString *)staticFilterPath
          staticFilterOffset:(int64_t)staticFilterOffset
          staticFilterLength:(int64_t)staticFilterLength
                     testnet:(BOOL)testnet
                     spvMode:(BOOL)spvMode
               signalHandler:(nullable id<DBILibraryListener>)signalHandler
                   extraArgs:(nonnull NSString *)extraArgs {
    try {
        ::ILibraryController::InitUnityLibThreaded(::djinni::String::toCpp(dataDir),
                                                   ::djinni::String::toCpp(staticFilterPath),
                                                   ::djinni::I64::toCpp(staticFilterOffset),
                                                   ::djinni::I64::toCpp(staticFilterLength),
                                                   ::djinni::Bool::toCpp(testnet),
                                                   ::djinni::Bool::toCpp(spvMode),
                                                   ::djinni_generated::ILibraryListener::toCpp(signalHandler),
                                                   ::djinni::String::toCpp(extraArgs));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)InitWalletFromRecoveryPhrase:(nonnull NSString *)phrase
                            password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = ::ILibraryController::InitWalletFromRecoveryPhrase(::djinni::String::toCpp(phrase),
                                                                                 ::djinni::String::toCpp(password));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)ContinueWalletFromRecoveryPhrase:(nonnull NSString *)phrase
                                password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = ::ILibraryController::ContinueWalletFromRecoveryPhrase(::djinni::String::toCpp(phrase),
                                                                                     ::djinni::String::toCpp(password));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)InitWalletLinkedFromURI:(nonnull NSString *)linkedUri
                       password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = ::ILibraryController::InitWalletLinkedFromURI(::djinni::String::toCpp(linkedUri),
                                                                            ::djinni::String::toCpp(password));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)ContinueWalletLinkedFromURI:(nonnull NSString *)linkedUri
                           password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = ::ILibraryController::ContinueWalletLinkedFromURI(::djinni::String::toCpp(linkedUri),
                                                                                ::djinni::String::toCpp(password));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)InitWalletFromAndroidLegacyProtoWallet:(nonnull NSString *)walletFile
                                   oldPassword:(nonnull NSString *)oldPassword
                                   newPassword:(nonnull NSString *)newPassword {
    try {
        auto objcpp_result_ = ::ILibraryController::InitWalletFromAndroidLegacyProtoWallet(::djinni::String::toCpp(walletFile),
                                                                                           ::djinni::String::toCpp(oldPassword),
                                                                                           ::djinni::String::toCpp(newPassword));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (DBLegacyWalletResult)isValidAndroidLegacyProtoWallet:(nonnull NSString *)walletFile
                                            oldPassword:(nonnull NSString *)oldPassword {
    try {
        auto objcpp_result_ = ::ILibraryController::isValidAndroidLegacyProtoWallet(::djinni::String::toCpp(walletFile),
                                                                                    ::djinni::String::toCpp(oldPassword));
        return ::djinni::Enum<::LegacyWalletResult, DBLegacyWalletResult>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)IsValidLinkURI:(nonnull NSString *)phrase {
    try {
        auto objcpp_result_ = ::ILibraryController::IsValidLinkURI(::djinni::String::toCpp(phrase));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)ReplaceWalletLinkedFromURI:(nonnull NSString *)linkedUri
                          password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = ::ILibraryController::ReplaceWalletLinkedFromURI(::djinni::String::toCpp(linkedUri),
                                                                               ::djinni::String::toCpp(password));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)EraseWalletSeedsAndAccounts {
    try {
        auto objcpp_result_ = ::ILibraryController::EraseWalletSeedsAndAccounts();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)IsValidRecoveryPhrase:(nonnull NSString *)phrase {
    try {
        auto objcpp_result_ = ::ILibraryController::IsValidRecoveryPhrase(::djinni::String::toCpp(phrase));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull DBMnemonicRecord *)GenerateRecoveryMnemonic {
    try {
        auto objcpp_result_ = ::ILibraryController::GenerateRecoveryMnemonic();
        return ::djinni_generated::MnemonicRecord::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)GenerateGenesisKeys {
    try {
        auto objcpp_result_ = ::ILibraryController::GenerateGenesisKeys();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull DBMnemonicRecord *)ComposeRecoveryPhrase:(nonnull NSString *)mnemonic
                                          birthTime:(int64_t)birthTime {
    try {
        auto objcpp_result_ = ::ILibraryController::ComposeRecoveryPhrase(::djinni::String::toCpp(mnemonic),
                                                                          ::djinni::I64::toCpp(birthTime));
        return ::djinni_generated::MnemonicRecord::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)TerminateUnityLib {
    try {
        ::ILibraryController::TerminateUnityLib();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull DBQrCodeRecord *)QRImageFromString:(nonnull NSString *)qrString
                                    widthHint:(int32_t)widthHint {
    try {
        auto objcpp_result_ = ::ILibraryController::QRImageFromString(::djinni::String::toCpp(qrString),
                                                                      ::djinni::I32::toCpp(widthHint));
        return ::djinni_generated::QrCodeRecord::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)GetReceiveAddress {
    try {
        auto objcpp_result_ = ::ILibraryController::GetReceiveAddress();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull DBMnemonicRecord *)GetRecoveryPhrase {
    try {
        auto objcpp_result_ = ::ILibraryController::GetRecoveryPhrase();
        return ::djinni_generated::MnemonicRecord::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)IsMnemonicWallet {
    try {
        auto objcpp_result_ = ::ILibraryController::IsMnemonicWallet();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)IsMnemonicCorrect:(nonnull NSString *)phrase {
    try {
        auto objcpp_result_ = ::ILibraryController::IsMnemonicCorrect(::djinni::String::toCpp(phrase));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSArray<NSString *> *)GetMnemonicDictionary {
    try {
        auto objcpp_result_ = ::ILibraryController::GetMnemonicDictionary();
        return ::djinni::List<::djinni::String>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)UnlockWallet:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = ::ILibraryController::UnlockWallet(::djinni::String::toCpp(password));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)LockWallet {
    try {
        auto objcpp_result_ = ::ILibraryController::LockWallet();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)IsWalletLocked {
    try {
        auto objcpp_result_ = ::ILibraryController::IsWalletLocked();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)ChangePassword:(nonnull NSString *)oldPassword
           newPassword:(nonnull NSString *)newPassword {
    try {
        auto objcpp_result_ = ::ILibraryController::ChangePassword(::djinni::String::toCpp(oldPassword),
                                                                   ::djinni::String::toCpp(newPassword));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)DoRescan {
    try {
        ::ILibraryController::DoRescan();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull DBUriRecipient *)IsValidRecipient:(nonnull DBUriRecord *)request {
    try {
        auto objcpp_result_ = ::ILibraryController::IsValidRecipient(::djinni_generated::UriRecord::toCpp(request));
        return ::djinni_generated::UriRecipient::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)IsValidNativeAddress:(nonnull NSString *)address {
    try {
        auto objcpp_result_ = ::ILibraryController::IsValidNativeAddress(::djinni::String::toCpp(address));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)IsValidBitcoinAddress:(nonnull NSString *)address {
    try {
        auto objcpp_result_ = ::ILibraryController::IsValidBitcoinAddress(::djinni::String::toCpp(address));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (int64_t)feeForRecipient:(nonnull DBUriRecipient *)request {
    try {
        auto objcpp_result_ = ::ILibraryController::feeForRecipient(::djinni_generated::UriRecipient::toCpp(request));
        return ::djinni::I64::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (DBPaymentResultStatus)performPaymentToRecipient:(nonnull DBUriRecipient *)request
                                      substractFee:(BOOL)substractFee {
    try {
        auto objcpp_result_ = ::ILibraryController::performPaymentToRecipient(::djinni_generated::UriRecipient::toCpp(request),
                                                                              ::djinni::Bool::toCpp(substractFee));
        return ::djinni::Enum<::PaymentResultStatus, DBPaymentResultStatus>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull DBTransactionRecord *)getTransaction:(nonnull NSString *)txHash {
    try {
        auto objcpp_result_ = ::ILibraryController::getTransaction(::djinni::String::toCpp(txHash));
        return ::djinni_generated::TransactionRecord::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSString *)resendTransaction:(nonnull NSString *)txHash {
    try {
        auto objcpp_result_ = ::ILibraryController::resendTransaction(::djinni::String::toCpp(txHash));
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSArray<DBAddressRecord *> *)getAddressBookRecords {
    try {
        auto objcpp_result_ = ::ILibraryController::getAddressBookRecords();
        return ::djinni::List<::djinni_generated::AddressRecord>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)addAddressBookRecord:(nonnull DBAddressRecord *)address {
    try {
        ::ILibraryController::addAddressBookRecord(::djinni_generated::AddressRecord::toCpp(address));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)deleteAddressBookRecord:(nonnull DBAddressRecord *)address {
    try {
        ::ILibraryController::deleteAddressBookRecord(::djinni_generated::AddressRecord::toCpp(address));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)PersistAndPruneForSPV {
    try {
        ::ILibraryController::PersistAndPruneForSPV();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)ResetUnifiedProgress {
    try {
        ::ILibraryController::ResetUnifiedProgress();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSArray<DBBlockInfoRecord *> *)getLastSPVBlockInfos {
    try {
        auto objcpp_result_ = ::ILibraryController::getLastSPVBlockInfos();
        return ::djinni::List<::djinni_generated::BlockInfoRecord>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (float)getUnifiedProgress {
    try {
        auto objcpp_result_ = ::ILibraryController::getUnifiedProgress();
        return ::djinni::F32::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull DBMonitorRecord *)getMonitoringStats {
    try {
        auto objcpp_result_ = ::ILibraryController::getMonitoringStats();
        return ::djinni_generated::MonitorRecord::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)RegisterMonitorListener:(nullable id<DBMonitorListener>)listener {
    try {
        ::ILibraryController::RegisterMonitorListener(::djinni_generated::MonitorListener::toCpp(listener));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (void)UnregisterMonitorListener:(nullable id<DBMonitorListener>)listener {
    try {
        ::ILibraryController::UnregisterMonitorListener(::djinni_generated::MonitorListener::toCpp(listener));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSDictionary<NSString *, NSString *> *)getClientInfo {
    try {
        auto objcpp_result_ = ::ILibraryController::getClientInfo();
        return ::djinni::Map<::djinni::String, ::djinni::String>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSArray<DBMutationRecord *> *)getMutationHistory {
    try {
        auto objcpp_result_ = ::ILibraryController::getMutationHistory();
        return ::djinni::List<::djinni_generated::MutationRecord>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nonnull NSArray<DBTransactionRecord *> *)getTransactionHistory {
    try {
        auto objcpp_result_ = ::ILibraryController::getTransactionHistory();
        return ::djinni::List<::djinni_generated::TransactionRecord>::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (BOOL)HaveUnconfirmedFunds {
    try {
        auto objcpp_result_ = ::ILibraryController::HaveUnconfirmedFunds();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (int64_t)GetBalance {
    try {
        auto objcpp_result_ = ::ILibraryController::GetBalance();
        return ::djinni::I64::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}


namespace djinni_generated {

auto ILibraryController::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto ILibraryController::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<DBILibraryController>(cpp);
}

}  // namespace djinni_generated

@end
