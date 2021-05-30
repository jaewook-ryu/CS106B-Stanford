#include "BankAccount.h"


// The Constructor
BankAccount::BankAccount(std::string name, double initDepoist){
    this->name = name;
    this->balance = initDepoist;
}

BankAccount::deposit(double amount){
    if(amount > 0){
        this->balance += amount;
    }
}

BankAccount::withdraw(double amount){
    if(amount <= depoist){
        this->balance = this->balance - amount;
    }
}
