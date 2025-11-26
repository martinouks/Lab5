#ifndef CLIENT_DATA_HPP
#define CLIENT_DATA_HPP

#include <string>
#include <iostream>

#include "Account.hpp"


class Client {
    private:
        std::string name;
        unsigned int id;

        //Dynamic array of pointers to accounts
        Account** accounts;
        std::size_t maxAccounts;
        std::size_t currentAccounts;
    
    public:
        Client(const std::string i_name, const unsigned int i_id, const unsigned int i_maxAccounts):
            name(i_name), id(i_id), maxAccounts(i_maxAccounts), currentAccounts(0){
                accounts = new Account*[maxAccounts];
            }

        Client(const Client& other):
            name(other.name), id(other.id), maxAccounts(other.maxAccounts), currentAccounts(other.currentAccounts){
                accounts = new Account*[maxAccounts];
                for(std::size_t i = 0; i < currentAccounts; i++){
                    accounts[i] = other.accounts[i];
                }
            }

        ~Client(){
            for(std::size_t i = 0; i < currentAccounts; i++){
                delete accounts[i];
            }
            delete[] accounts;
        }

        bool createAccount(){
            if(currentAccounts >= maxAccounts){
                std::cout << "Maximum number of accounts reached." << std::endl;
                return false;
            }
            std::cout << "Creation of a current account (1), unblocked savings account (2), or blocked savings account (3)? ";
            int choice;
            std::cin >> choice;
            switch(choice){
                case 1:
                    accounts[currentAccounts++] = new CurrentAccount(id);
                    break;
                case 2:
                    accounts[currentAccounts++] = new UnblockedAccount(id);
                    break;
                case 3:
                    accounts[currentAccounts++] = new BlockedAccount(id);
                    break;
                default:
                    std::cout << "Invalid choice." << std::endl;
                    return false;
            }
            return true;
        }

        bool credit(const std::size_t accountIndex, const double amount){
            if(accountIndex >= currentAccounts){
                std::cout << "Invalid account index." << std::endl;
                return false;
            }
            accounts[accountIndex]->add(amount);
            return true;
        }

        bool debit(const std::size_t accountIndex, const double amount){
            if(accountIndex >= currentAccounts){
                std::cout << "Invalid account index." << std::endl;
                return false;
            }
            const double taken = accounts[accountIndex]->take(amount);
            return taken > 0;
        }

        void displayClient() const {
            std::cout << "Client Name: " << name << ", ID: " << id << std::endl;
            for(std::size_t i = 0; i < currentAccounts; i++){
                std::cout << "Account " << i << ": " << *(accounts[i]) << std::endl;
            }
        }
    }


#endif 