#include "Customer.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Transaction.h"
#include <fstream>
using namespace std;

// // Работа с файлами
void saveAccountsToFile(const Customer& customer, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < customer.accountCount; ++i) {
            if (customer.accounts[i]->accountType == AccountType::Savings) {
                auto savingsAcc = dynamic_cast<SavingsAccount*>(customer.accounts[i]);
                if (savingsAcc) {
                    outFile << "Savings " << savingsAcc->accountNumber << " " << savingsAcc->balance << " " << savingsAcc->interestRate << "\n";
                }
            } else if (customer.accounts[i]->accountType == AccountType::Checking) {
                auto checkingAcc = dynamic_cast<CheckingAccount*>(customer.accounts[i]);
                if (checkingAcc) {
                    outFile << "Checking " << checkingAcc->accountNumber << " " << checkingAcc->balance << " " << checkingAcc->overdraftLimit << "\n";
                }
            }
        }
    }
    outFile.close();
}

void loadAccountsFromFile(Customer& customer, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    string accNum;
    double balance;
    string accType;
    double number;
    while (inFile >> accType >> accNum >> balance >> number) {
        if (accType == "Savings") {
            customer.addAccount(new SavingsAccount(accNum, balance, number));
        } else if (accType == "Checking") {
            customer.addAccount(new CheckingAccount(accNum, balance, number));
        }
    }
    inFile.close();
}

void userInterface() {
    Customer customer("Victor");

    int choice;
    do {
        cout << "\nBanking system menu:\n";
        cout << "1. Create savings account\n";
        cout << "2. Create checking account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Add interest\n";
        cout << "6. Display accounts\n";
        cout << "7. Save accounts to File\n";
        cout << "8. Load accounts from File\n";
        cout << "9. Compare accounts by balance\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string accNum;
                double initialBalance, interestRate;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                cout << "Enter interest rate: ";
                cin >> interestRate;
                customer.addAccount(new SavingsAccount(accNum, initialBalance, interestRate));
                break;
            }
            case 2: {
                string accNum;
                double initialBalance, overdraftLimit;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                cout << "Enter overdraft limit: ";
                cin >> overdraftLimit;
                customer.addAccount(new CheckingAccount(accNum, initialBalance, overdraftLimit));
                break;
            }
            case 3: {
                string accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter deposit amount: ";
                cin >> amount;
                BankAccount* acc = customer.findAccount(accNum);
                if (acc) {
                    Transaction::deposit(*acc, amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                string accNum;
                double amount;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                BankAccount* acc = customer.findAccount(accNum);
                if (acc) {
                    Transaction::withdraw(*acc, amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 5: {
                string accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                BankAccount* acc = customer.findAccount(accNum);
                if (acc) {
                    if (acc->accountType == AccountType::Savings) {
                        auto savingsAcc = dynamic_cast<SavingsAccount*>(acc);
                        if (savingsAcc) {
                            Transaction::addInterest(savingsAcc);
                        }
                    } else {
                        cout << "Account does not support adding interests";
                    }
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 6:
                customer.displayAccounts();
                break;
            case 7: {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                saveAccountsToFile(customer, filename);
                break;
            }
            case 8: {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                loadAccountsFromFile(customer, filename);
                break;
            }
            case 9: {
                string accNum1, accNum2;
                int operation;
                cout << "Enter first account number: ";
                cin >> accNum1;
                cout << "Enter second account number: ";
                cin >> accNum2;
                cout << "Select operation: 1. >; 2. <; 3. ==: ";
                cin >> operation;
                BankAccount* acc1 = customer.findAccount(accNum1);
                BankAccount* acc2 = customer.findAccount(accNum2);
                if (acc1 == nullptr || acc2 == nullptr) {
                    cout << "Account not found.\n";
                    break;
                }
                switch (operation) {
                case 1:
                    cout << (*acc1 > *acc2) << "\n";
                    break;
                case 2:
                    cout << (*acc1 < *acc2) << "\n";
                    break;
                case 3:
                    cout << (*acc1 == *acc2) << "\n";
                    break;
                
                default:
                    break;
                }
            }
                break;
            case 10:
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);
}

int main() {
    userInterface();
}