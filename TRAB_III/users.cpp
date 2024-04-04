#include "users.hpp"


bool Host::showCars()
{  
    if (m_cars.size() == 0)
    { 
        return false ;
    }
    else{
         for (int i = 0; i < m_cars.size(); i++)
    {
        cout << "Car " << i+1 << endl;
        cout << "Brand: " << m_cars[i].getBrand() << endl;
        cout << "Model: " << m_cars[i].getModel() << endl;
        cout << "Color: " << m_cars[i].getColor() << endl;
        cout << "Year: " << m_cars[i].getYear() << endl;
        cout << "Price: " << m_cars[i].getCarPrice() << endl;
        cout<< "------------------------" << endl;
        cout << endl;
    }
    return true;
    }
     
}

void Host::addCar()
{
    string brand, model, color;
    size_t year;
    float price;
    cout << "Put de brand of the car: ";
    cin >> brand; cout << endl;
    cout << "Put the model of the car: ";
    cin >> model; cout << endl;
    cout << "Put the color of the car: ";
    cin >> color; cout << endl;
    cout << "Put the year of the car: ";
    cin >> year; cout << endl;
    cout << "Put the price per hour of the car: ";
    cin >> price; cout << endl;
    Car car(brand, model, color, year, price);
    m_cars.push_back(car);
}

void Host::removeCar()
{
    showCars();
    int car;
    cout << "Put the number of the car you want to remove: ";
    cin >> car; cout << endl;
    m_cars.erase(m_cars.begin() + car - 1);
    cout << "Car removed" << endl;
}

void Host::showOcupiedCars()
{
    
    for (int i = 0; i < m_cars.size(); i++)
    {
        size_t control = 0;
        if (m_cars[i].getOcupied() == true)
        {
            control++;
            cout << "Car " << i+1 << endl;
            cout << "Brand: " << m_cars[i].getBrand() << endl;
            cout << "Model: " << m_cars[i].getModel() << endl;
            cout << "Color: " << m_cars[i].getColor() << endl;
            cout << "Year: " << m_cars[i].getYear() << endl;
            cout << "Price: " << m_cars[i].getCarPrice() << endl;
            cout<< "------------------------" << endl;
            cout << endl;
        }
        if (control == 0)
        {
            cout << "There are no ocupied cars" << endl << endl;
        }
    }
}

Car* Host::showFreeCars()
{
    for (int i = 0; i < m_cars.size(); i++)
    {
        if (m_cars[i].getOcupied() == false)
        {
            cout << "Car " << i+1 << endl;
            cout << "Brand: " << m_cars[i].getBrand() << endl;
            cout << "Model: " << m_cars[i].getModel() << endl;
            cout << "Color: " << m_cars[i].getColor() << endl;
            cout << "Year: " << m_cars[i].getYear() << endl;
            cout << "Price: " << m_cars[i].getCarPrice() << endl;
            cout<< "------------------------" << endl;
            cout << endl;
        }
    }
    size_t car;
    cout<< "Select your car: ";
    cin >> car; cout << endl;
    
    return &m_cars[car-1];
}
void Host::editCar()
{
    showCars();
    int car;
    cout << "Put the number of the car you want to edit: ";
    cin >> car; cout << endl;
    string brand, model, color;
    size_t year;
    float price;
    cout << "Put de brand of the car: ";
    cin >> brand; cout << endl;
    cout << "Put the model of the car: ";
    cin >> model; cout << endl;
    cout << "Put the color of the car: ";
    cin >> color; cout << endl;
    cout << "Put the year of the car: ";
    cin >> year; cout << endl;
    cout << "Put the price of the car: ";
    cin >> price; cout << endl;
    m_cars[car - 1].setBrand(brand);
    m_cars[car - 1].setModel(model);
    m_cars[car - 1].setColor(color);
    m_cars[car - 1].setYear(year);
    m_cars[car - 1].setPrice(price);
}


bool Client::getCar()
{
    if(m_car != NULL)
    {
    cout << "Brand: " << m_car->getBrand() << endl;
    cout << "Model: " << m_car->getModel() << endl;
    cout << "Color: " << m_car->getColor() << endl;
    cout << "Year: " << m_car->getYear() << endl;
    cout << "Price: " << m_car->getCarPrice() << endl;
    cout << endl;
    return true;
    }
    else
    {
        return false;
    }
   
}