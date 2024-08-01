/*
abstract class is preferred to use when providing common functionality for related classes.
however, it can't be used when multiple inheritance is needed. 
*/

#include <iostream>

const double PI = 3.14;

// abstract class
class Shape {
public:
    virtual double area() = 0; // pure virtual function

    void draw() { // common implemented function for derived classes to inherit
        std::cout << "drawing a shape\n";
    }
};


// derived class
class Circle : public Shape {
public:
    double area() { // overriden method
        return PI * radius * radius;
    }

    void setRadius(int radius) {
        this->radius = radius;
    }

private:
    int radius;
};

// another derived class
class Square : public Shape {
public: 
    double area() { // overriden method
        return side * side;
    }

    void setSide(int side) {
        this->side = side;
    }

private:
    int side;
};

