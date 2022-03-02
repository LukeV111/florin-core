// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

package com.florin.jniunifiedbackend;

/** Interface to receive wallet level events */
public abstract class IWalletListener {
    public abstract void notifyBalanceChange(BalanceRecord newBalance);

    /**
     * Notification of new mutations.
     * If selfCommitted it is due to a call to performPaymentToRecipient, else it is because of a transaction
     * reached us in another way. In general this will be because we received funds from someone, hower there are
     * also cases where funds is send from our wallet while !selfCommitted (for example by a linked desktop wallet
     * or another wallet instance using the same keys as ours).
     *
     * Note that no notifyNewMutation events will fire until after 'notifySyncDone'
     * Therefore it is necessary to first fetch the full mutation history before starting to listen for this event.
     */
    public abstract void notifyNewMutation(MutationRecord mutation, boolean selfCommitted);

    /**
     * Notification that an existing transaction/mutation  has updated
     *
     * Note that no notifyUpdatedTransaction events will fire until after 'notifySyncDone'
     * Therefore it is necessary to first fetch the full mutation history before starting to listen for this event.
     */
    public abstract void notifyUpdatedTransaction(TransactionRecord transaction);
}
