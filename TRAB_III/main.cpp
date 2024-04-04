#include "users.hpp"

int main()
{
    Host host("host", "1234");
    vector<Client> clients;
    size_t c;

    while(c != 0)
    {
        cout<< "1. Enter with host" << endl;
        cout<< "2. Enter with client" << endl;
        cout <<"3. Register a new client" << endl;
        cout<< "0. Exit" << endl;
        cout <<"Choose an option: ";
        cin >> c; cout << endl;
        switch (c)
        {
            case 1:
            {
                string password;
                cout << "Put the password: ";
                cin >> password; cout << endl;
                if ( password == host.getPassword() )
                {
                    size_t c2;
                    while(c2 != 0)
                    {
                        cout << "1. Show cars" << endl;
                        cout << "2. Add car" << endl;
                        cout << "3. Remove car" << endl;
                        cout << "4. Show ocupied cars" << endl;
                        cout << "5. Edit car" << endl;
                        cout << "6. Number of active clients" << endl;
                        cout << "7. Link car to client" << endl;
                        cout << "8. Unlink car from client" << endl;
                        cout << "0. Return " << endl;
                        cout << "Choose an option: ";
                        cin >> c2; cout << endl;
                        switch (c2)
                        {
                            case 1:
                            {
                               if( host.showCars()== false) 
                                {
                                   cout << "There are no cars" << endl << endl;
                                }
                                continue;
                            }
                            case 2:
                            {
                                host.addCar();
                                continue;
                            }
                            case 3:
                            {
                                host.removeCar();
                                continue;
                            }
                            case 4:
                            {
                                host.showOcupiedCars();
                                continue;
                            }
                            case 5:
                            {
                                host.editCar();
                                continue;
                            }
                           
                            case 6:
                            {
                                host.showClients();
                                continue;
                            }
                          
                            case 7:
                            {
                                size_t c5;
                                for(size_t i = 0; i < clients.size(); i++)
                                {
                                    cout << i + 1 << ". " << clients[i].getName() << endl;
                                }
                                cout << "Choose a client: ";
                                cin >> c5; cout << endl;
                                Car* car = host.showFreeCars();
                                cout << "How many days will the car be rented? ";
                                size_t devolucion; cin>>devolucion; cout << endl;
                                host.linkCar(&clients.at(c5-1), car, devolucion);
                                
                               
                              continue;
                            }
                            case 8:
                            {
                                size_t c4;
                                for(size_t i = 0; i < clients.size(); i++)
                                {
                                    cout << i + 1 << ". " << clients[i].getName() << endl;
                                }
                                cout << "Choose a client: ";
                                cin >> c4; cout << endl;
                                host.unlinkCar(&clients.at(c4 - 1));
                                continue;
                            }
                            case 0:
                            {
                                continue;
                            }
                            default:
                            {
                                cout << "Invalid option" << endl;
                                continue;
                            }
                        }
                    }
                    c2 = 1;
                }
                else
                 {
                    cout << "Invalid password" << endl;
                    continue;

                 }   
                
                continue;
               
            } 

            case 2:
            {
                string name, password;
                bool found = false;
                cout << "Put the name: ";
                cin >> name; cout << endl;
                cout << "Put the password: ";
                cin >> password; cout << endl;
                for (size_t i = 0; i < clients.size(); i++)
                {
                    if (clients[i].getName() == name && clients[i].getPassword() == password)
                    {
                      found = true;
                      cout<< "Welcome " << name << endl << endl;
                      cout<<"Your datas are: " << endl << endl;
                      if(clients[i].getCar()==false)
                      {
                          cout << "You don't have a car" << endl;
                      }
                      cout << endl;
                      cout << " The price of the car is: " << clients[i].getPrice() << endl << endl;
                    }
                    
                }
                if (found == false)
                {
                    cout << "Invalid name or password" << endl << endl;
                    continue;
                }
                continue;
            }

            case 3:
            {
                string name, password;
                cout << "Put the name: ";
                cin >> name; cout << endl;
                cout << "Put the password: ";
                cin >> password; cout << endl;
                clients.push_back(Client(name, password));
                host.newClient();
                cout << "Client created" << endl;
                continue;
            } 
            case 0:
            {
                continue;
            }
            default:
            {
                cout << "Invalid option" << endl<<endl;     
                continue;
            }  
            


        }      
        
    }
    
    return 0;
}