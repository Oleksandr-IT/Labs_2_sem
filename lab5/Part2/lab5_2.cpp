#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string text;

    cout << "Введіть текст(англ): ";
    getline(cin, text);

    int upperCount = 0;
    for (char c : text) {
        if (c >= 'A' && c <= 'Z') {
            upperCount++;
        }
    }

    stringstream ss(text);
    string word;

    int minLen = 1000;

    while (ss >> word) {
        if (word.length() < minLen) {
            minLen = word.length();
        }
    }

    cout << "\nКількість великих літер: " << upperCount << endl;
    cout << "Слова з найменшою кількістю літер:\n";

    stringstream ss2(text);
    while (ss2 >> word) {
        if (word.length() == minLen) {
            cout << word << endl;
        }
    }

    return 0;
}