#ifndef USERS_HPP
#define USERS_HPP
#include "cars.hpp"

class User {
    protected:
        string m_name;
        string m_password;
        
        

    public:
        User(): m_name(" "), m_password(" ") {};
        User(string name, string password): m_name(name), m_password(password) {};
        ~User(){};
        string getName() {return m_name;};
        string getPassword() {return m_password;};
        void setPassword(string password) {m_password = password;};
       
};
class Client :public User {
    protected:
        Car *m_car;
        size_t m_devolucion;
        float m_price;

    public:
        Client(): User(), m_car(NULL), m_devolucion(0), m_price(0) {};
        Client(string name, string password, Car *car = NULL, size_t devolucion = 0, float price = 0): User(name, password), m_car(car), m_devolucion(devolucion), m_price(price) {};
        ~Client() {};
        bool getCar();

        void setCar(Car *car) {m_car = car; m_price = car->getCarPrice()*m_devolucion;};
        void operator >>(Car *car){setCar(car);};

        void setNullCar() {m_car = NULL; m_price = 0;};

        void setDevolution(size_t devolucion) {m_devolucion = devolucion;};
        void operator ||(size_t devolucion) {setDevolution(devolucion);};

        size_t getDevolution() {return m_devolucion;};
        float getPrice() {return m_price;};

        
};


class Host :public User {
    protected:
        vector<Car> m_cars;
        float m_balance;
        size_t m_clients;
        
    public:
        Host(): User(), m_balance(0), m_clients(0) {};
        Host(string name, string password, float balance = 0, size_t clients = 0): User(name, password), m_balance(balance), m_clients(clients) {};
        ~Host() {};
        bool showCars();
        void newClient() {m_clients++;};
        void addCar();
        void removeCar();
        void showOcupiedCars();
        Car* showFreeCars();
        void editCar();
        void showBalance() {cout << "The balance is: " << m_balance << endl;};
        void showClients() {cout << "We have " << m_clients <<" actives clients in this moment."<<endl <<endl;};
        void linkCar(Client *client, Car *car, size_t devolution){client->setDevolution(devolution); client->setCar(car)  ;car->setOcupied(true); m_balance += car->getCarPrice();};

        void unlinkCar(Client *client) { client->setNullCar();};
        void operator <<(Client client) {unlinkCar(&client);};


    
};





#endif