/* Polymorphism allows methods to do different things based on the object 
that it is acting upon, even though they share the same name. */

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow" << endl;
    }
};

void makeSound(Animal* animal) {
    animal->sound();
}

int main() {
    Dog dog;
    Cat cat;

    makeSound(&dog); // Output: Bark
    makeSound(&cat); // Output: Meow
    return 0;
}