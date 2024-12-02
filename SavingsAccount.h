#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"

// Класс для сберегательного счета
class SavingsAccount : public BankAccount {
public:
    double interestRate; // Процентная ставка

    SavingsAccount(const string& accNum, double initialBalance, double interest);

    // Реализация обработки транзакций
    void processTransaction(double amount) override;

    // Метод для начисления процентов
    void addInterest();
};

#endif // SAVINGS_ACCOUNT_H