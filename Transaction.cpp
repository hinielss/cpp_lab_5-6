#include "Transaction.h"

void Transaction::deposit(BankAccount& account, double amount) {
    account.processTransaction(amount);
}

void Transaction::withdraw(BankAccount& account, double amount) {
    account.processTransaction(-amount);
}

void Transaction::addInterest(SavingsAccount* account) {
    account->addInterest();
}