#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include "client.hpp"

class Account
{

    protected:
        Client* m_client;
        float m_balance;
    
    public:
        Account() : m_client(NULL) , m_balance(0.0) {};
        Account( Client* client,float balance= 0) : m_balance(balance), m_client(client) {};
        ~Account() {};
        string getInformation();
        void deposit(float value);
        void transfer(float value);
        void getBalance();
};

class Saccount : public Account
{
    protected:
        float m_limit;
    
    public:
        Saccount() :Account(), m_limit(0) {};
        Saccount(Client* client, float balance =0, float limit=1000) : Account(client, balance), m_limit(limit) {};
        ~Saccount();
        
};


#endif