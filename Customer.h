#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "BankAccount.h"
#include <string>

// Класс для представления клиента
class Customer {
private:
    static const int maxAccounts = 100; // Максимальное количество счетов
public:
    string name;
    int accountCount;
    BankAccount* accounts[maxAccounts];  // Массив указателей на счета

    Customer(const string& customerName);
    ~Customer();

    // Метод для добавления нового счета
    void addAccount(BankAccount* account);

    // Метод для отображения всех счетов клиента
    void displayAccounts() const;

    // Метод для отображения всех счетов клиента
    BankAccount* findAccount(const string& accNum);
};

#endif // CUSTOMER_H