#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const string& accNum, double initialBalance, double interest)
    : BankAccount(accNum, initialBalance, AccountType::Savings), interestRate(interest) {}

void SavingsAccount::processTransaction(double amount) {
    if (amount < 0 && balance + amount < 0) {
        cout << "Insufficient funds for withdrawal.\n";
    } else {
        balance += amount;
    }
}

void SavingsAccount::addInterest() {
    balance += balance * interestRate;
}