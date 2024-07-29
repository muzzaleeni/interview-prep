/* Inheritance allows a new class to inherit properties and behaviors (methods) 
from an existing class. This promotes code reusability and establishes a 
relationship between classes. */

#include <iostream>
using namespace std;

class Vehicle {
public:
    void honk() {
        cout << "Honking!" << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "Driving a car" << endl;
    }
};

int main() {
    Car myCar;
    myCar.honk(); // Output: Honking!
    myCar.drive(); // Output: Driving a car
    return 0;
}