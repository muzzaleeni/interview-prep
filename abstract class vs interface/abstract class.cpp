/* Use an abstract class when you want to provide common functionality or default
 implementations that can be shared among derived classes. */

#include <iostream>

class Shape {
public:
    virtual double area() = 0; // Pure virtual function
    virtual double perimeter() = 0; // Pure virtual function

    void printInfo() {
        std::cout << "Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14 * radius * radius;
    }

    double perimeter() override {
        return 2 * 3.14 * radius;
    }
};