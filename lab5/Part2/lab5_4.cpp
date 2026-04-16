#include <iostream>
#include <windows.h>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    vector<int> numbers;
    int num;
    ifstream f("IntNumbers.txt");

    if (f.is_open()) {
        while (f>>num) {
            if (num>0) {
                numbers.push_back(num);
            }
        }
        f.close();
    }
    else
        cerr << "Помилка відкриття файлу!" << endl;

    queue<int> even_num;
    vector<int> sort_num;
    for (int n : numbers) {
        if (n % 2 == 0) {
            sort_num.push_back(n);
        }
    }

    sort(sort_num.begin(), sort_num.end(), greater<int>());
    auto min_it = min_element(sort_num.begin(), sort_num.end());//Найменший елемент черги
    for (int x : sort_num) {
        if (x==*min_it) {
            continue;
        }
        even_num.push(x);
    }
    even_num.pop();//Видалення першого(найбільшого) елемента
    while (!even_num.empty()) {
        cout << even_num.front() << " ";
        even_num.pop();
    }
    return 0;
}

