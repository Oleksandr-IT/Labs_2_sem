#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual double perimeter() const = 0;
    virtual ~Figure() {} // віртуальний деструктор
};

class Rectangle : public Figure {
private:
    double a, b;
public:
    Rectangle(double a, double b) : a(a), b(b) {}

    double perimeter() const override {
        return 2 * (a + b);
    }
};

class Circle : public Figure {
private:
    double r;
public:
    Circle(double r) : r(r) {}

    double perimeter() const override {
        return 2 * M_PI * r;
    }
};

class RightTriangle : public Figure {
private:
    double a, b;
public:
    RightTriangle(double a, double b) : a(a), b(b) {}

    double perimeter() const override {
        double c = sqrt(a * a + b * b);
        return a + b + c;
    }
};

class Trapezoid : public Figure {
private:
    double a, b, c, d;
public:
    Trapezoid(double a, double b, double c, double d)
        : a(a), b(b), c(c), d(d) {}

    double perimeter() const override {
        return a + b + c + d;
    }
};

int main() {
    Figure* figures[4];

    figures[0] = new Rectangle(3, 4);
    figures[1] = new Circle(5);
    figures[2] = new RightTriangle(3, 4);
    figures[3] = new Trapezoid(3, 5, 4, 6);

    for (int i = 0; i < 4; i++) {
        cout << "Perimeter: " << figures[i]->perimeter() << endl;
    }

    // очищення пам'яті
    for (int i = 0; i < 4; i++) {
        delete figures[i];
    }

    return 0;
}