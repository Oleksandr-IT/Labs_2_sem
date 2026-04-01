#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

void x(const int a,const int b,const int c) {
    try {
        const double d=pow(b,2)-4*a*c, t1 = (-b-sqrt(d))/(2*a), t2 = (-b+sqrt(d))/(2*a);
        if (a == 0)
            throw invalid_argument("Це не біквадратне рівняння!");
        if (d < 0)
            throw runtime_error("Рівняння не має дійсних розв'язків.");

        bool found = false;
        cout << "Корені рівняння:\n";
        if (t1 >= 0) {
            cout << "x1 = " << sqrt(t1) << endl;
            cout << "x2 = " << -sqrt(t1) << endl;
            found = true;
        }

        if (t2 >= 0 && t2 != t1) {
            cout << "x3 = " << sqrt(t2) << endl;
            cout << "x4 = " << -sqrt(t2) << endl;
            found = true;
        }

        if (!found)
            throw runtime_error("Отримані корені є сторонніми.");
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout<<"1) ";
    x(1, -5, 4);
    cout<<endl<<"2) ";
    x(1, 5, 4);
    cout<<endl<<"3) ";
    x(0, 2, 3);
    cout<<endl<<"4) ";
    x(1, 1, 1);
    return 0;
}