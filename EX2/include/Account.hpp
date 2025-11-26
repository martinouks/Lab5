#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP


#include <iostream>


#define IRATEBLOCKED 0.04
#define IRATEUNBLOCKED 0.02*

std::ostream& operator<<(std::ostream& os, const Account& account){
    os << "Account Bank ID: " << account.bankId << ", Balance: " << account.balance;
    return os;
}

class Account {
    protected:
        double balance;
        unsigned int bankId;

        friend std::ostream& operator<<(std::ostream& os, const Account& account);
    
    public:
        Account(const unsigned int i_bankId = 0): balance(0.0), bankId(i_bankId) {}

        void add(const double amount){
            balance += amount;
        };

        virtual
        const double take(const double amount)=0;

        const unsigned int getBankId() const {
            return bankId;
        }
};

class CurrentAccount: public Account {
    public:
        CurrentAccount(const unsigned int i_bankId = 0): Account(i_bankId) {}

        const double take(const double amount) override {
            if (amount < balance) {
                balance -= amount;
                return amount;
            } else {
                if (balance == 0) {
                    std::cout << "Insufficient funds." << std::endl;
                    return 0;
                }
                int taken = balance;
                balance = 0;
                return taken;
            }
        }
};

class SavingsAccount: public Account {
    protected:
        double rate;
    
    public:
        SavingsAccount(const unsigned int i_bankId, const double i_rate): Account(i_bankId), rate(i_rate) {}

        void addInterest() {
            balance += balance * rate;
        }
};


class BlockedAccount: public SavingsAccount {
    public:
        BlockedAccount(const unsigned int i_bankId):
            SavingsAccount(i_bankId, IRATEBLOCKED) {}

        const double take(const double amount) override {
            std::cout << "Withdrawals are not allowed from a blocked account." << std::endl;
            return -1;
        }
};

class UnblockedAccount: public SavingsAccount {
    public:
        UnblockedAccount(const unsigned int i_bankId):
            SavingsAccount(i_bankId, IRATEUNBLOCKED) {}

        const double take(const double amount) override {
            if (amount < balance) {
                balance -= amount;
                return amount;
            } else {
                std::cout << "Insufficient funds." << std::endl;
                return 0;
            }
        }
};



#endif