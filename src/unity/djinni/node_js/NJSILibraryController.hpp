// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#ifndef DJINNI_GENERATED_NJSILIBRARYCONTROLLER_HPP
#define DJINNI_GENERATED_NJSILIBRARYCONTROLLER_HPP


#include "NJSILibraryListener.hpp"
#include "NJSMonitorListener.hpp"
#include "address_record.hpp"
#include "block_info_record.hpp"
#include "input_record.hpp"
#include "legacy_wallet_result.hpp"
#include "mnemonic_record.hpp"
#include "monitor_record.hpp"
#include "mutation_record.hpp"
#include "output_record.hpp"
#include "payment_result_status.hpp"
#include "qr_code_record.hpp"
#include "transaction_record.hpp"
#include "uri_recipient.hpp"
#include "uri_record.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <napi.h>
#include <uv.h>
#include <i_library_controller.hpp>

using namespace std;

class NJSILibraryController: public Napi::ObjectWrap<NJSILibraryController> {
public:

    static Napi::FunctionReference constructor;
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    NJSILibraryController(const Napi::CallbackInfo& info) : Napi::ObjectWrap<NJSILibraryController>(info){};

private:
    /** Get the build information (ie. commit id and status) */
    Napi::Value BuildInfo(const Napi::CallbackInfo& info);

    /**
     * Start the library
     * extraArgs - any additional commandline arguments as could normally be passed to the daemon binary
     * NB!!! This call blocks until the library is terminated, it is the callers responsibility to place it inside a thread or similar.
     * If you are in an environment where this is not possible (node.js for example use InitUnityLibThreaded instead which places it in a thread on your behalf)
     */
    Napi::Value InitUnityLib(const Napi::CallbackInfo& info);

    /** Threaded implementation of InitUnityLib */
    void InitUnityLibThreaded(const Napi::CallbackInfo& info);

    /** Create the wallet - this should only be called after receiving a `notifyInit...` signal from InitUnityLib */
    Napi::Value InitWalletFromRecoveryPhrase(const Napi::CallbackInfo& info);

    /** Continue creating wallet that was previously erased using EraseWalletSeedsAndAccounts */
    Napi::Value ContinueWalletFromRecoveryPhrase(const Napi::CallbackInfo& info);

    /** Create the wallet - this should only be called after receiving a `notifyInit...` signal from InitUnityLib */
    Napi::Value InitWalletLinkedFromURI(const Napi::CallbackInfo& info);

    /** Continue creating wallet that was previously erased using EraseWalletSeedsAndAccounts */
    Napi::Value ContinueWalletLinkedFromURI(const Napi::CallbackInfo& info);

    /** Create the wallet - this should only be called after receiving a `notifyInit...` signal from InitUnityLib */
    Napi::Value InitWalletFromAndroidLegacyProtoWallet(const Napi::CallbackInfo& info);

    /** Check if a file is a valid legacy proto wallet */
    Napi::Value isValidAndroidLegacyProtoWallet(const Napi::CallbackInfo& info);

    /** Check link URI for validity */
    Napi::Value IsValidLinkURI(const Napi::CallbackInfo& info);

    /** Replace the existing wallet accounts with a new one from a linked URI - only after first emptying the wallet. */
    Napi::Value ReplaceWalletLinkedFromURI(const Napi::CallbackInfo& info);

    /**
     * Erase the seeds and accounts of a wallet leaving an empty wallet (with things like the address book intact)
     * After calling this it will be necessary to create a new linked account or recovery phrase account again.
     * NB! This will empty a wallet regardless of whether it has funds in it or not and makes no provisions to check for this - it is the callers responsibility to ensure that erasing the wallet is safe to do in this regard.
     */
    Napi::Value EraseWalletSeedsAndAccounts(const Napi::CallbackInfo& info);

    /**
     * Check recovery phrase for (syntactic) validity
     * Considered valid if the contained mnemonic is valid and the birth-number is either absent or passes Base-10 checksum
     */
    Napi::Value IsValidRecoveryPhrase(const Napi::CallbackInfo& info);

    /** Generate a new recovery mnemonic */
    Napi::Value GenerateRecoveryMnemonic(const Napi::CallbackInfo& info);

    Napi::Value GenerateGenesisKeys(const Napi::CallbackInfo& info);

    /** Compute recovery phrase with birth number */
    Napi::Value ComposeRecoveryPhrase(const Napi::CallbackInfo& info);

    /** Stop the library */
    void TerminateUnityLib(const Napi::CallbackInfo& info);

    /** Generate a QR code for a string, QR code will be as close to width_hint as possible when applying simple scaling. */
    Napi::Value QRImageFromString(const Napi::CallbackInfo& info);

    /** Get a receive address for the active account */
    Napi::Value GetReceiveAddress(const Napi::CallbackInfo& info);

    /** Get the recovery phrase for the wallet */
    Napi::Value GetRecoveryPhrase(const Napi::CallbackInfo& info);

    /** Check if the wallet is using a mnemonic seed ie. recovery phrase (else it is a linked wallet) */
    Napi::Value IsMnemonicWallet(const Napi::CallbackInfo& info);

    /** Check if the phrase mnemonic is a correct one for the wallet (phrase can be with or without birth time) */
    Napi::Value IsMnemonicCorrect(const Napi::CallbackInfo& info);

    /**
     * Get the 'dictionary' of valid words that a recovery phrase can be composed of
     * NB! Not all combinations of these words are valid
     * Do not use this to generate/compose your own phrases - always use 'GenerateRecoveryMnemonic' for this
     * This function should only be used for input validation/auto-completion
     */
    Napi::Value GetMnemonicDictionary(const Napi::CallbackInfo& info);

    /** Unlock wallet */
    Napi::Value UnlockWallet(const Napi::CallbackInfo& info);

    /** Forcefully lock wallet again */
    Napi::Value LockWallet(const Napi::CallbackInfo& info);

    Napi::Value IsWalletLocked(const Napi::CallbackInfo& info);

    /** Change the wallet password */
    Napi::Value ChangePassword(const Napi::CallbackInfo& info);

    /** Rescan blockchain for wallet transactions */
    void DoRescan(const Napi::CallbackInfo& info);

    /** Check if text/address is something we are capable of sending money too */
    Napi::Value IsValidRecipient(const Napi::CallbackInfo& info);

    /** Check if text/address is a native (to our blockchain) address */
    Napi::Value IsValidNativeAddress(const Napi::CallbackInfo& info);

    /** Check if text/address is a valid bitcoin address */
    Napi::Value IsValidBitcoinAddress(const Napi::CallbackInfo& info);

    /** Compute the fee required to send amount to given recipient */
    Napi::Value feeForRecipient(const Napi::CallbackInfo& info);

    /** Attempt to pay a recipient, will throw on failure with description */
    Napi::Value performPaymentToRecipient(const Napi::CallbackInfo& info);

    /**
     * Get the wallet transaction for the hash
     * Will throw if not found
     */
    Napi::Value getTransaction(const Napi::CallbackInfo& info);

    /** resubmit a transaction to the network, returns the raw hex of the transaction as a string or empty on fail */
    Napi::Value resendTransaction(const Napi::CallbackInfo& info);

    /** Get list of all address book entries */
    Napi::Value getAddressBookRecords(const Napi::CallbackInfo& info);

    /** Add a record to the address book */
    void addAddressBookRecord(const Napi::CallbackInfo& info);

    /** Delete a record from the address book */
    void deleteAddressBookRecord(const Napi::CallbackInfo& info);

    /** Interim persist and prune of state. Use at key moments like app backgrounding. */
    void PersistAndPruneForSPV(const Napi::CallbackInfo& info);

    /**
     * Reset progress notification. In cases where there has been no progress for a long time, but the process
     * is still running the progress can be reset and will represent work to be done from this reset onwards.
     * For example when the process is in the background on iOS for a long long time (but has not been terminated
     * by the OS) this might make more sense then to continue the progress from where it was a day or more ago.
     */
    void ResetUnifiedProgress(const Napi::CallbackInfo& info);

    /** Get info of last blocks (at most 32) in SPV chain */
    Napi::Value getLastSPVBlockInfos(const Napi::CallbackInfo& info);

    Napi::Value getUnifiedProgress(const Napi::CallbackInfo& info);

    Napi::Value getMonitoringStats(const Napi::CallbackInfo& info);

    void RegisterMonitorListener(const Napi::CallbackInfo& info);

    void UnregisterMonitorListener(const Napi::CallbackInfo& info);

    Napi::Value getClientInfo(const Napi::CallbackInfo& info);

    /**
     * Get list of wallet mutations
     *NB! This is SPV specific, non SPV wallets should use account specific getMutationHistory on an accounts controller instead
     */
    Napi::Value getMutationHistory(const Napi::CallbackInfo& info);

    /**
     * Get list of all transactions wallet has been involved in
     *NB! This is SPV specific, non SPV wallets should use account specific getTransactionHistory on an accounts controller instead
     */
    Napi::Value getTransactionHistory(const Napi::CallbackInfo& info);

    /**
     * Check if the wallet has any transactions that are still pending confirmation, to be used to determine if e.g. it is safe to perform a link or whether we should wait.
     *NB! This is SPV specific, non SPV wallets should use HaveUnconfirmedFunds on wallet controller instead
     */
    Napi::Value HaveUnconfirmedFunds(const Napi::CallbackInfo& info);

    /**
     * Check current wallet balance (including unconfirmed funds)
     *NB! This is SPV specific, non SPV wallets should use GetBalance on wallet controller instead
     */
    Napi::Value GetBalance(const Napi::CallbackInfo& info);

};
#endif //DJINNI_GENERATED_NJSILIBRARYCONTROLLER_HPP
