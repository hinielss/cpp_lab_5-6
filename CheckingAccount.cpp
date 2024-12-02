#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const string& accNum, double initialBalance, double overdraft)
    : BankAccount(accNum, initialBalance, AccountType::Checking), overdraftLimit(overdraft) {}

void CheckingAccount::processTransaction(double amount) {
    if (amount < 0 && balance + amount < -overdraftLimit) {
        cout << "Overdraft limit exceeded.\n";
    } else {
        balance += amount;
    }
}