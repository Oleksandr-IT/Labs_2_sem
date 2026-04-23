#include <iostream>

using namespace std;

class A {
public:
    int a;
    A() { cout << "A ctor\n"; }
    ~A() { cout << "A dtor\n"; }
};

class B {
public:
    int b;
    B() { cout << "B ctor\n"; }
    ~B() { cout << "B dtor\n"; }
};

class C : public A, public B {
public:
    int c;
    C() { cout << "C ctor\n"; }
    ~C() { cout << "C dtor\n"; }
};

class D : public C {
public:
    int d;
    D() { cout << "D ctor\n"; }
    ~D() { cout << "D dtor\n"; }
};

class E : public B {
public:
    int e;
    E() { cout << "E ctor\n"; }
    ~E() { cout << "E dtor\n"; }
};

class F : public C {
public:
    int f;
    F() { cout << "F ctor\n"; }
    ~F() { cout << "F dtor\n"; }
};

class Av {
public:
    int a;
    Av() { cout << "Av ctor\n"; }
    virtual ~Av() { cout << "Av dtor\n"; }
};

class Bv {
public:
    int b;
    Bv() { cout << "Bv ctor\n"; }
    virtual ~Bv() { cout << "Bv dtor\n"; }
};

class Cv : virtual public Av, virtual public Bv {
public:
    int c;
    Cv() { cout << "Cv ctor\n"; }
    ~Cv() { cout << "Cv dtor\n"; }
};

class Dv : public Cv {
public:
    int d;
    Dv() { cout << "Dv ctor\n"; }
    ~Dv() { cout << "Dv dtor\n"; }
};

class Ev : virtual public Bv {
public:
    int e;
    Ev() { cout << "Ev ctor\n"; }
    ~Ev() { cout << "Ev dtor\n"; }
};

class Fv : public Cv {
public:
    int f;
    Fv() { cout << "Fv ctor\n"; }
    ~Fv() { cout << "Fv dtor\n"; }
};

int main() {
    cout << "\n--- WITHOUT VIRTUAL ---\n";
    F f1;
    D d1;
    E e1;

    cout << "Size A: " << sizeof(A) << endl;
    cout << "Size B: " << sizeof(B) << endl;
    cout << "Size C: " << sizeof(C) << endl;
    cout << "Size D: " << sizeof(D) << endl;
    cout << "Size E: " << sizeof(E) << endl;
    cout << "Size F: " << sizeof(F) << endl;

    cout << "\n--- WITH VIRTUAL ---\n";
    Fv f2;
    Dv d2;
    Ev e2;

    cout << "Size Av: " << sizeof(Av) << endl;
    cout << "Size Bv: " << sizeof(Bv) << endl;
    cout << "Size Cv: " << sizeof(Cv) << endl;
    cout << "Size Dv: " << sizeof(Dv) << endl;
    cout << "Size Ev: " << sizeof(Ev) << endl;
    cout << "Size Fv: " << sizeof(Fv) << endl;

    return 0;
}