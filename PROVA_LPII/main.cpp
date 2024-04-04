#include "shape.hpp"


int main()
{

    vector<Shape2d*> shapes;
    int c;
    while(c != 0)
    {   
        cout<< endl;
        cout << "    UFSC SHAPE MANAGER   " << endl;
        cout << "--------------------------" << endl;
        cout << "1. Insert a Circle" << endl;
        cout << "2. Insert a Triangle" << endl;
        cout << "3. Insert a Square" << endl;
        cout << "4. Insert a Polygon" << endl;
        cout << "5. Show Perimeters" << endl;
        cout << "6. Quit" << endl;
        cout << "Select an option: ";
        cin >> c;
         
        if(c == 1){
            size_t ratio;
            cout << endl<<"Enter the radius: ";
            cin >> ratio;
            shapes.push_back(new Circle(ratio));
        }
        else if(c == 2){
            int x, y;
            
            cout << endl<<  "Enter the first point"<<endl;
            cout << "cordinates x: ";
            cin >> x;
            cout << "cordinates y: ";
            cin >> y;
            Point2d p1(x, y);

            cout << endl<< "Enter the second point"<<endl;
            cout << "cordinates x: ";
            cin >> x;
            cout << "cordinates y: ";
            cin >> y;
            Point2d p2(x, y);

            cout << endl<< "Enter the third point"<<endl;
            cout << "cordinates x: ";
            cin >> x;
            cout << "cordinates y: ";
            cin >> y;
            Point2d p3(x, y);

            shapes.push_back(new Triangle(p1, p2, p3));
        }
        else if(c == 3){
            size_t edge;
            cout <<endl<< "Enter the edge: ";
            cin >> edge;
            shapes.push_back(new Square(edge));
        }
        else if(c == 4){
            vector<Point2d> vertices;
            int n;
            cout <<endl << "Enter the number of vertices: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                int x,y;
                cout << endl<< "Enter the " << i+1 << "th vertex "<< endl;
                cout << "cordinate x: ";
                cin >> x;
                cout << "cordinate y: ";
                cin >> y;
                Point2d p(x, y);
                vertices.push_back(p);
            }
            shapes.push_back(new Polygon(vertices));
        }
        else if(c == 5){
            for(int i = 0; i < shapes.size(); i++){
                cout << endl << "INDEX: " << i+1 << endl;
                cout << "OBJECT: " << shapes.at(i)->getId() << endl;
                cout << "PERIMETER: " << shapes.at(i)->getPerimeter() << endl;
        
            }
        }
        else if(c == 6){
            break;
        }
        else{
            
            cout << "Invalid option!" << endl << endl;
        }
    }

    while( 0 < shapes.size()){
        delete shapes.at(0);
        shapes.erase(shapes.begin());
    }
    
    cout << endl << "Bye!" << endl;
   


    return 0;
}