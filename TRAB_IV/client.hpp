#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Client {
    protected: 
        string m_name;
        string m_profession;
        float m_income;

    public:
        Client() : m_name(" "), m_profession(" "), m_income(0.0) {};
        Client(string name, string porfession="", float income=0): m_name(name), m_profession(porfession), m_income(income) {};
        ~Client() {};
        
        string getName() {return m_name;};
        string getProfession() {return m_profession;};
        float getIncome() {return m_income;};
        void setName(string name);
        void setProfesion(string profesion);
        void setIncome(float income);
        
};



#endif