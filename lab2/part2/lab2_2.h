#pragma once
using namespace std;
template <typename T>
class Matrix {
private:
    int n;
    T** arr;

public:
    Matrix(int size) {
        n = size;
        arr = new T*[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new T[n];
        }
    }

    void input() {
        cout << "Введіть елементи матриці " << n << "x" << n << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
    }

    void print() {
        cout << "Матриця:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    T diagonalSum() {
        T sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i][i];
        }
        return sum;
    }

    ~Matrix() {
        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

#ifndef LABS_2_SEM_LAB2_2_H
#define LABS_2_SEM_LAB2_2_H

#endif //LABS_2_SEM_LAB2_2_H
