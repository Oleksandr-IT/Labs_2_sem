#include <iostream>
#include <windows.h>

using namespace std;

class Base {
protected:
    int dat;
public:
    Base() : dat(1) {}
    Base(int d) : dat(d) {}
};

/*class D1 : protected Base {
protected:
    int d1;
public:
    D1() : d1(1) {}
    D1(int d, int dt) : Base(dt), d1(d) {}
};

class D2 : protected Base {
protected:
    double d2;
public:
    D2() : d2(1) {}
    D2(int d, double dt) : Base(d), d2(dt) {}
};

class D12 : protected D1, protected D2 {
protected:
    double dt;
public:
    D12() : dt(1) {}
    D12(int a, int b, int c, double d, int e) : D1(a, b), D2(c, d), dt(e) {}
};

class R : protected D12, protected Base {
protected:
    double dt;
public:
    R() : dt(1) {}
    R(int a, int b, int c, double d, int e) : D12(a, b, c, d, e), Base(a), dt(e + 1.0) {}

    void showDat() {
        cout << "\nНевіртуальні з'єднання класу R:" << endl;
        cout << "D12::D1::Base::dat = " << D12::D1::Base::dat << endl;
        cout << "Direct Base::dat   = " << Base::dat << endl;
        cout << "D12::D2::Base::dat = " << D12::D2::Base::dat << endl;
    }
};*/

//Ієрархія з віртуальним успадкуванням
class D1V : virtual protected Base {
protected:
    int d1;
public:
    D1V() : d1(1) {}
    D1V(int d, int dt) : Base(dt), d1(d) {}
};

class D2V : virtual protected Base {
protected:
    double d2;
public:
    D2V() : d2(1) {}
    D2V(int d, double dt) : Base(d), d2(dt) {}
};

class D12V : virtual protected D1V, virtual protected D2V {
protected:
    double dt;
public:
    D12V() : dt(1) {}
    D12V(int a, int b, int c, double d, int e) : D1V(a, b), D2V(c, d), dt(e) {}
};

class RV : virtual protected D12V, virtual protected Base {
protected:
    double dt;
public:
    RV() : dt(1) {}
    RV(int a, int b, int c, double d, int e) : Base(a + 1), D12V(a, b, c, d, e), dt(e + 1.0) {}

    void showDat() {
        cout << "\nВіртуальні з'єднання класу RV:" << endl;
        cout << "Напряму dat (немає неоднозначності) = " << dat << endl;
        cout << "D12V::D1V::Base::dat      = " << D12V::D1V::Base::dat << endl;
        cout << "Base::dat                 = " << Base::dat << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    //R a, b(1, 2, 3, 4.5, 5);
    RV av, bv(1, 2, 3, 4.5, 5);

    /*cout << "--- Розміри невіртуальних класів ---" << endl;
    cout << "Розмір Base: " << sizeof(Base) << endl;
    cout << "Розмір D1:   " << sizeof(D1) << endl;
    cout << "Розмір D2:   " << sizeof(D2) << endl;
    cout << "Розмір D12:  " << sizeof(D12) << endl;
    cout << "Розмір R:    " << sizeof(R) << " (об'єкт b: " << sizeof(b) << ")" << endl;*/

    cout << "\n--- Розміри віртуальних класів ---" << endl;
    cout << "Розмір D1V:  " << sizeof(D1V) << endl;
    cout << "Розмір D2V:  " << sizeof(D2V) << endl;
    cout << "Розмір D12V: " << sizeof(D12V) << endl;
    cout << "Розмір RV:   " << sizeof(RV) << " (об'єкт bv: " << sizeof(bv) << ")" << endl;

    //b.showDat();
    bv.showDat();

    return 0;
}