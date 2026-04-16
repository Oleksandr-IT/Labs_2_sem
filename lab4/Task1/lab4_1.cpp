#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// Algorithm #2
double T1(double x) {
    ifstream data1("dat1.dat");
    if (!data1) throw runtime_error("Can't open dat1.dat");
    return atan(acos(sin(2*x)));
}

double U1(double x) {
    ifstream data1("dat1.dat");
    if (!data1) throw runtime_error("Can't open dat1.dat");
    return atan(asin(sin(3*x)));
}

double Qqn1(double x, double y, double z) {
    ifstream data1("dat1.dat");
    if (!data1) throw runtime_error("Can't open dat1.dat");
    return (x/U1(x))+(y*T1(y))-(U1(z)*T1(z));
}

double Qnk1(double x, double y) {
    ifstream data1("dat1.dat");
    if (!data1) throw runtime_error("Can't open dat1.dat");
    return (1.1 * Qqn1(x, y, x + y)) - (0.9 * Qqn1(y, x, x - y));
}

double Rnk(double x, double y) {
    ifstream data1("dat1.dat");
    if (!data1) throw runtime_error("Can't open dat1.dat");
    return (x*Qnk1(x, y))+(y*Qnk1(y, x))-(0.03*Qnk1(x,y)*Qnk1(y,x));
}

// Algorithm #3

double Qqn2(double x, double y, double z) {
    ifstream data1("dat1.dat");
    ifstream data2("dat2.dat");
    ifstream data3("dat3.dat");
    if (!data1) throw runtime_error("Can't open dat1.dat");
    if (!data2) throw runtime_error("Can't open dat2.dat");
    if (!data3) throw runtime_error("Can't open dat3.dat");
    return (x/U1(x))+(y*T1(y))-(0.9*U1(z)*T1(z));
}

double Qnk2(double x, double y) {
    ifstream data1("dat1.dat");
    if (!data1) throw runtime_error("Can't open dat1.dat");
    return (1.3*Qqn1(x,y,x))-(0.7*Qqn1(y,x,x));
}

double funk(double x, double y) {
    ifstream data1("dat1.dat");
    if (!data1) throw runtime_error("Can't open dat1.dat");
    return (1.75*x*Qnk2(x,y))+(1.25*y*Qnk2(y,x))-(1.5*Qnk2(x,y)*Qnk2(y,x));
}

// Algorithm #1
/*double Variant(double r, double k) {
    r=func(x,y,z);
}*/

double Y(double x) {
    int k=0;
    //log(x*sqrt(100-(x*x)));
    if ((100-(x*x)<0)) return k=0;
    if (x*sqrt(100-(x*x))<1) return k=0;
}

double Yrr(double f, double r) {
    return Y(f)*r+0.5*Y(r);
}

double Trr(double f, double r) {
    int k=0;
    return ((4*(f*f))-r)<0?k=0:sqrt(4*(f*f))+0.5*Yrr(r,f);
}

double k(double f, double r) {
    return (f*Trr(f,r))+(r*Trr(f,2*k));
}