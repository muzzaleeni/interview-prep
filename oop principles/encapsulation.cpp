/* Encapsulation is the bundling of data (attributes) and methods (functions) 
that operate on the data into a single unit, typically a class. This principle 
helps in restricting direct access to some of the object's components, which 
is a means of preventing unintended interference and misuse of the methods and data. */

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int mileage;

public:
    // Constructor
    Car(string b, string m) : brand(b), model(m), mileage(0) {}

    // Method to drive the car
    void drive(int distance) {
        mileage += distance;
    }

    // Method to display car details
    void showData() {
        cout << "Brand: " << brand << ", Model: " << model << ", Mileage: " << mileage << endl;
    }
};

int main() {
    Car myCar("Toyota", "Corolla");
    myCar.drive(100);
    myCar.showData(); // Output: Brand: Toyota, Model: Corolla, Mileage: 100
    return 0;
}