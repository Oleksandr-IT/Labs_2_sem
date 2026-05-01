#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {
        cout << "Особа\n";
    }

    virtual ~Person() {
        cout << "Особа\n";
    }

    virtual void show() const {
        cout << "Ім'я: " << name << ", Вік: " << age << endl;
    }
};

class Woman : virtual public Person {
protected:
    string gender;

public:
    Woman(string n = "", int a = 0)
        : Person(n, a), gender("Жінка") {
        cout << "Жінка\n";
    }

    void show() const override {
        Person::show();
        cout << "стать: " << gender << endl;
    }
};

class Employee : virtual public Person {
protected:
    double salary;

public:
    Employee(string n = "", int a = 0, double s = 0)
        : Person(n, a), salary(s) {
        cout << "Працівник\n";
    }

    void show() const override {
        Person::show();
        cout << "Зарплата: " << salary << endl;
    }
};

class WomanEmployee : public Woman, public Employee {
public:
    WomanEmployee(string n, int a, double s)
        : Person(n, a), Woman(n, a), Employee(n, a, s) {
        cout << "Працівник-жінка\n";
    }

    void show() const override {
        Person::show();
        cout << "Стать: Жінка\n";
        cout << "Зарплата: " << salary << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    WomanEmployee w("Наталія", 21, 15000);

    cout << "\n--- Інформація ---\n";
    w.show();

    return 0;
}