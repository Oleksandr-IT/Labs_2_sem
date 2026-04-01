#include <iostream>
#include <string>
#include <windows.h>
#include "lab2_1.h"

using namespace std;

bool checkBrackets(string expr) {
    Stack st;

    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }

        else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.isEmpty())
                return false;

            char top = st.peek();

            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                st.pop();
                }
            else {
                return false;
            }
        }
    }

    return st.isEmpty();
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string expr;

    cout << "Введіть вираз: ";
    getline(cin, expr);

    if (checkBrackets(expr))
        cout << "Дужки розміщені правильно." << endl;
    else
        cout << "Помилка у розміщенні дужок." << endl;

    return 0;
}