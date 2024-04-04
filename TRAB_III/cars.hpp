#ifndef CARS_HPPP
#define CARS_HPPP
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Car {
    protected :
        string m_brand;
        string m_model;
        string m_color;
        size_t m_year;
        float m_price;
        bool m_ocupied;
       
    
    public: 
        Car(): m_brand(" "), m_model(" "), m_color(" "), m_year(0), m_price(0), m_ocupied(false) {};
        Car(string brand="", string model="", string color="", size_t year=0, float price=0, bool ocupied=false): m_brand(brand), m_model(model), m_color(color), m_year(year), m_price(price), m_ocupied(ocupied) {};
        ~Car() {};
        string getBrand() {return m_brand;};
        string getModel() {return m_model;};
        string getColor() {return m_color;};
        size_t getYear() {return m_year;};
        float getCarPrice() {return m_price;};
        bool getOcupied() {return m_ocupied;};
        void setBrand(string brand) {m_brand = brand;};
        void setModel(string model) {m_model = model;};
        void setColor(string color) {m_color = color;};
        void setYear(size_t year) {m_year = year;};

        void setPrice(float price) {m_price = price;};
        void operator ==(float price) {setPrice(price);};

        void setOcupied(bool ocupied) {m_ocupied = ocupied;};
        void operator !=(bool ocupied) {setOcupied(ocupied);};
       
};




#endif