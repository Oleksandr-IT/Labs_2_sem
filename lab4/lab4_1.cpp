#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

template <typename T>
T findMin(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    srand(time(0));

    int a, b;
    double x, y;

    cout << "Введіть 2 цілих числа: ";
    cin >> a >> b;

    cout << "Введіть 2 дійсних числа: ";
    cin >> x >> y;

    cout << "\nЦілі числа:\n";
    cout << "Min = " << findMin(a, b) << endl;
    cout << "Max = " << findMax(a, b) << endl;

    cout << "\nДійсні числа:\n";
    cout << "Min = " << findMin(x, y) << endl;
    cout << "Max = " << findMax(x, y) << endl;

    cout << "\nЗчитування з файлу\n";
    ifstream fin("num.txt");

    if (fin) {
        fin >> a >> b >> x >> y;

        cout << "Цілі числа: Min = " << findMin(a, b)
             << ", Max = " << findMax(a, b) << endl;

        cout << "Дійсні числа: Min = " << findMin(x, y)
             << ", Max = " << findMax(x, y) << endl;

        fin.close();
    } else {
        cout << "Файл не знайдено!\n";
    }

    cout << "\nРандомні числа\n";

    a = rand() % 100;
    b = rand() % 100;

    x = (rand() % 1000) / 10.0; // 0.0 - 100.0
    y = (rand() % 1000) / 10.0;

    cout << "Згенеровані цілі числа: " << a << " " << b << endl;
    cout << "Min = " << findMin(a, b)
         << ", Max = " << findMax(a, b) << endl;

    cout << "Згенеровані дійсні числа: " << x << " " << y << endl;
    cout << "Min = " << findMin(x, y)
         << ", Max = " << findMax(x, y) << endl;
    return 0;
}