#include "account.hpp"

string Account::getInformation()
{
    stringstream sst;

    if(m_client == NULL)
    {
        sst << "Client not informed";
    }
    else{
        sst << "Client Name: "<< m_client->getName() <<"Profession: " << m_client->getProfession() << "Income: " << m_client->getIncome() << "Balance: " << m_balance;
    }
    
    return sst.str();
};

