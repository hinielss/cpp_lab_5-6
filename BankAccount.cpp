#include "BankAccount.h"

// Преобразование типа счета в строку
const char* getStringAccountType(AccountType v) {
    switch (v) {
        case AccountType::Savings: return "Savings";
        case AccountType::Checking: return "Checking";
    }
    return "Unknown";
}

BankAccount::BankAccount(const string& accNum, double initialBalance, AccountType type)
    : accountNumber(accNum), balance(initialBalance), accountType(type) {}

BankAccount::~BankAccount() {}

ostream& operator<<(ostream& os, const BankAccount& account) {
    os << "Account Number: " << account.accountNumber
       << ", Balance: " << account.balance
       << ", Type: " << getStringAccountType(account.accountType);
    return os;
}

bool BankAccount::operator==(const BankAccount& other) const {
    return this->balance == other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return this->balance > other.balance;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return this->balance < other.balance;
}