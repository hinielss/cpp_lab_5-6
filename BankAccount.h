#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

// Перечисление типов счетов
enum class AccountType { Savings, Checking };

// Вспомогательная функция для преобразования AccountType в строку
inline const char* getStringAccountType(AccountType v);

// Базовый класс для всех типов банковских счетов
class BankAccount {
public:
    string accountNumber;
    double balance;
    AccountType accountType;

    BankAccount(const string& accNum, double initialBalance, AccountType type);
    virtual ~BankAccount();

    // Виртуальный метод для обработки транзакций
    virtual void processTransaction(double amount) = 0;

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const BankAccount& account);

    // Перегрузка операторов сравнения
    bool operator==(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
};

#endif // BANK_ACCOUNT_H