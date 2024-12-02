cmake_minimum_required(VERSION 3.10)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 17)

# Все исходные файлы
set(SOURCES
    main.cpp
    BankAccount.cpp
    SavingsAccount.cpp
    CheckingAccount.cpp
    Customer.cpp
    Transaction.cpp
)

add_executable(BankingSystem ${SOURCES})