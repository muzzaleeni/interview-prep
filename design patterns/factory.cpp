/* In a transportation application, different types of vehicles
 (like cars and bikes) can be created using a factory method.
 This allows the application to create vehicle objects without
 specifying the exact class of vehicle being created. */

#include <iostream>

class Vehicle {
public:
    virtual void create() = 0;
};

class Car : public Vehicle {
public:
    void create() override {
        std::cout << "Car created." << std::endl;
    }
};

class Bike : public Vehicle {
public:
    void create() override {
        std::cout << "Bike created." << std::endl;
    }
};

class VehicleFactory {
public:
    static Vehicle* getVehicle(const std::string& type) {
        if (type == "car") {
            return new Car();
        } else if (type == "bike") {
            return new Bike();
        }
        return nullptr;
    }
};

int main() {
    Vehicle* vehicle1 = VehicleFactory::getVehicle("car");
    vehicle1->create();
    
    Vehicle* vehicle2 = VehicleFactory::getVehicle("bike");
    vehicle2->create();
    
    delete vehicle1;
    delete vehicle2;
    return 0;
}