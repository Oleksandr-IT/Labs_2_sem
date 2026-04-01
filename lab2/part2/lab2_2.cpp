#include <iostream>
#include <windows.h>
#include "lab2_2.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Matrix<int> m1(3);
    m1.input();
    m1.print();
    cout << "Сума головної діагоналі = " << m1.diagonalSum() << endl;

    Matrix<double> m2(2);
    m2.input();
    m2.print();
    cout << "Сума головної діагоналі = " << m2.diagonalSum() << endl;

    return 0;
}