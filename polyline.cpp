#include <iostream>
#include <vector>
#include <cmath>

class Polyline {
public:
    // Конструктур и деструктор, если необходимы
    Polyline() : data() {}

    // Добавить очередную точку в ломаную
    void addPoint(double x, double y) {
        data.emplace_back(x, y);
    }

    // Получить количесто точек в ломаной в данный момент
    unsigned int getNumberOfPoints() const {
        return std::size(data);
    }

    // Получить длину ломаной в данный момент
    double getLength() const {
        auto result = 0.;
        for(auto it = std::begin(data); it != std::prev(std::end(data)); it++) {
            result += std::sqrt(std::pow(it->first - std::next(it)->first, 2) +
                    std::pow(it->second - std::next(it)->second, 2));
        }
        return result;
    }

    // Получить x-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getX(unsigned int i) const {
        return data[i].first;
    }

    // Получить y-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getY(unsigned int i) const {
        return data[i].second;
    }

private:
    std::vector<std::pair<double, double>> data;

};

using std::cout, std::endl;

int main()
{
    Polyline p;
    p.addPoint(0.0, 0.0);
    p.addPoint(1.0, 0.0);
    p.addPoint(1.0, 1.0);
    cout << "Length: " << p.getLength() << endl;
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.getNumberOfPoints(); i++) {
        cout << p.getX(i) << " " << p.getY(i) << endl;
    }
    return 0;
}