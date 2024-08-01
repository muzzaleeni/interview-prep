/*
interface is used when unrelated classes share similar behaviours, but not necessarily exactly the same.
we can't use interface when need to provide default implementation
*/

#include <iostream>

class Walking {
public:
    virtual void walk() = 0;
};

class Flying {
public:
    virtual void fly() = 0;
};

class Eagle : public Walking, public Flying {
public:
    void walk() {
        std::cout << "I can walk\n";
    }

    void fly() {
        std::cout << "I can fly\n";
    }
};
