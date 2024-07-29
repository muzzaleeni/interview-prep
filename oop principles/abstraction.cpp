/* Abstraction involves hiding complex implementation details and 
showing only the essential features of the object. */

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    
    shape1->draw(); // Output: Drawing a Circle
    shape2->draw(); // Output: Drawing a Square

    delete shape1;
    delete shape2;
    return 0;
}