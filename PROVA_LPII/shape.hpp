#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Point2d{
   
   

    public:
    int m_x;
    int m_y;
    Point2d(): m_x(0), m_y(0){};
    Point2d(int x, int y): m_x(x), m_y(y){};
    ~Point2d(){};
    float distance(Point2d p);
    float getX(){return m_x;};
    float getY(){return m_y;};

};


class Shape2d{

   
  
public: 
    string m_id;
    float m_perimeter;
    Shape2d(): m_perimeter(0), m_id("") {};
    ~Shape2d(){}; 
    virtual float getPerimeter(){return m_perimeter;};
    string getId(){return m_id;};


   
};


class Circle : public Shape2d{

    protected:
    size_t m_ratio;

    public:
    Circle(){};
    Circle(size_t ratio): m_ratio(ratio){ m_id = "Circle";};
    ~Circle(){};
    float getPerimeter();

};

class Triangle : public Shape2d{

    protected:
    Point2d m_p1;
    Point2d m_p2;
    Point2d m_p3;


    public:
    Triangle(){};
    Triangle(Point2d p1, Point2d p2, Point2d p3): m_p1(p1), m_p2(p2), m_p3(p3){ m_id = "Triangle";};
    ~Triangle(){};
    float getPerimeter();

};

class Square : public Shape2d{

    protected:
    size_t m_edge;

    public:
    Square(){};
    Square(size_t edge): m_edge(edge){ m_id = "Square";};
    ~Square(){};
    float getPerimeter();

};

class Polygon : public Shape2d{

    protected:
    vector<Point2d> m_vertices;

    public:
    Polygon(){};
    Polygon(vector<Point2d> vertices): m_vertices(vertices){ m_id = "Polygon";};
    ~Polygon(){};
    float getPerimeter();

};

#endif