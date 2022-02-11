#include <iostream>
#include <cmath>
#include <vector>

class Figure {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Circle: public Figure {
public:
    Circle(double r): r(r) {};
    double area() override {
        return std::acos(-1) * r * r;
    }
    double perimeter() override {
        return 2 * std::acos(-1) * r;
    }

private:
    double r;
};

class Rectangle: public Figure {
public:
    Rectangle(double a, double b): a(a), b(b) {}
    double area() override {
        return a * b;
    }
    double perimeter() override {
        return 2 * (a + b);
    }
private:
    double a, b;
};

class Square: public Rectangle {
public:
    Square(double a) : Rectangle(a, a) {}
};

template <typename T>
void print(T arg) {
    std::cout << arg << ' ';
}

template<typename T, typename ... Types>
void print(T arg1, Types ... args) {
    std::cout << arg1 << ' ';
    print(args...);
}

int main() {
//    Square square(5);
//    Rectangle rectangle(2, 3);
//    Circle circle(5);
//
//    std::cout << "Square: area is " << square.area() <<
//        ", perimeter is " << square.perimeter() << std::endl;
//
//    std::vector<Figure*> figures;
//    figures.push_back(&square);
//    figures.push_back(&rectangle);
//    figures.push_back(&circle);
//    for(auto ptr: figures) {
//        std::cout << "Area is " << ptr->area() << std::endl;
//    }

    return 0;
}
