#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "SavingsAccount.h"
#include "CheckingAccount.h"

// Класс для обработки транзакции
class Transaction {
public:
    // Внесение депозита на счет
    static void deposit(BankAccount& account, double amount);

    // Снятие средств со счета
    static void withdraw(BankAccount& account, double amount);

    // Начисление процентов на сберегательный счет
    static void addInterest(SavingsAccount* account);
};

#endif // TRANSACTION_H