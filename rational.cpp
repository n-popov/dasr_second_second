#include <iostream>
#include <numeric>

class Rational {
public:
    // Конструктор дроби, здесь a - числитель, b - знаменатель
    Rational(int a, int b): numerator(a), denominator(b) {}

    friend Rational operator+(Rational, Rational);

    friend std::ostream& operator<<(std::ostream& os, Rational r) {
        return os << r.numerator << '/' << r.denominator;
    }

    // Реализуйте операторы:
    // - сложения двух дробей

    // - вычитания двух дробей

    Rational operator-(Rational other) {
        auto lcm = std::lcm(denominator, other.denominator);
        return {numerator * (lcm / denominator) -
                other.numerator * (lcm / other.denominator), lcm};
    }
    // - умножения двух дробей
    // - деления двух дробей
    // - умножения дроби на целое число (должно работать при любом порядке операндов)

private:
    int numerator, denominator;
};

Rational operator+(Rational lhs, Rational rhs) {
    auto lcm = std::lcm(lhs.denominator, rhs.denominator);
    return {lhs.numerator * (lcm / lhs.denominator) +
                    rhs.numerator * (lcm / rhs.denominator), lcm};
}

using std::cout, std::endl;

int main() {
    Rational a(1, 2);
    Rational b(2, 3);

    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;

    return 0;
}