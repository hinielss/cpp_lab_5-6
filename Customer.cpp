#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(const string& customerName) : name(customerName), accountCount(0) {}

Customer::~Customer() {
    for (int i = 0; i < accountCount; ++i) {
        delete accounts[i];
    }
}

void Customer::addAccount(BankAccount* account) {
    if (accountCount < maxAccounts) {
        accounts[accountCount++] = account;
    } else {
        cout << "Cannot add more accounts. Maximum limit reached.\n";
    }
}

void Customer::displayAccounts() const {
    cout << "Customer: " << name << "\n";
    for (int i = 0; i < accountCount; ++i) {
        cout << *accounts[i] << "\n";
    }
}

BankAccount* Customer::findAccount(const string& accNum) {
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i]->accountNumber == accNum)
            return accounts[i];
    }
    return nullptr;
}