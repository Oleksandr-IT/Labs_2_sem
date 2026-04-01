#include <iostream>
using namespace std;

int main() {
    char ch;
    int pos = 0; // позиція в поточному рядку

    while (cin.get(ch)) {
        if (ch == '\t') {
            int spaces = 10 - (pos % 10);

            for (int i = 0; i < spaces; i++) {
                cout << ' ';
                pos++;
            }
        }
        else if (ch == '\n') {
            cout << ch;
            pos = 0;
        }
        else {
            cout << ch;
            pos++;
        }
    }

    return 0;
}