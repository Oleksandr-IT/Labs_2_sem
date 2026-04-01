#include <iostream>
#include <stdexcept>
#include <windows.h>
#include "lab2_3.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    try {
        GardenTree* trees[3];

        trees[0] = new AppleTree(3, false);
        trees[1] = new CherryTree(7, true);
        trees[2] = new PearTree(2, false);

        for (int i = 0; i < 3; i++) {
            trees[i]->show();
            trees[i]->transplantDecision();
            cout << endl;
        }

        for (int i = 0; i < 3; i++)
            delete trees[i];
    }
    catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}