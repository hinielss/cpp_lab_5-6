#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "BankAccount.h"

// Класс для расчетного счета
class CheckingAccount : public BankAccount {
public:
    double overdraftLimit; // Лимит на овердрафт

    CheckingAccount(const string& accNum, double initialBalance, double overdraft);

    // Реализация обработки транзакций
    void processTransaction(double amount) override;
};

#endif // CHECKING_ACCOUNT_H