#ifndef _BANKACCOUNT_H
#define _BANKACCOUNT_H


class BankAccount{
public:
    BankAccount(std::string n, double d);
    void deposit(double amount);
    void withdraw(double amount);

private:
    std::string name;
    double balance;
};

#endif // BANKACCOUNT_H
