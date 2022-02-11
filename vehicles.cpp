#include <iostream>

// Абстрактное транспортное средство
class Vehicle {
public:
    // Может ли ездить по суще
    virtual bool canDrive() const {
        return false;
    }

    // Может ли плавать
    virtual bool canSail() const {
        return false;
    }

    // Может ли летать
    virtual bool canFly() const {
        return false;
    }

    virtual ~Vehicle() {};
};

class Car: public Vehicle {
public:
    bool canDrive() const override {
        return true;
    }
};

class Ship: public Vehicle {
public:
    bool canSail() const override {
        return true;
    }
};

class Plane: public Vehicle {
public:
    bool canFly() const override {
        return true;
    }
};

class Truck : public Car {};

int main()
{
    std::cout << std::boolalpha;
    Vehicle* v;

    v = new Car();
    std::cout << "Car can drive: " << v->canDrive() << std::endl;
    std::cout << "Car can sail: " << v->canSail() << std::endl;
    std::cout << "Car can fly: " << v->canFly() << std::endl;
    delete v;

    v = new Ship();
    std::cout << "Ship can drive: " << v->canDrive() << std::endl;
    std::cout << "Ship can sail: " << v->canSail() << std::endl;
    std::cout << "Ship can fly: " << v->canFly() << std::endl;
    delete v;

    v = new Plane();
    std::cout << "Plane can drive: " << v->canDrive() << std::endl;
    std::cout << "Plane can sail: " << v->canSail() << std::endl;
    std::cout << "Plane can fly: " << v->canFly() << std::endl;
    delete v;

    Car* c = new Truck();
    std::cout << "Truck can drive: " << c->canDrive() << std::endl;
    std::cout << "Truck can sail: " << c->canSail() << std::endl;
    std::cout << "Truck can fly: " << c->canFly() << std::endl;
    delete c;

    return 0;
}