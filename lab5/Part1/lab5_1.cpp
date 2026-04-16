#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

class Student {
private:
    string name;
    int age;
    double avgMark;

public:
    Student(string n = "", int a = 0, double m = 0.0)
        : name(n), age(a), avgMark(m) {}

    double getMark() const {
        return avgMark;
    }

    friend istream& operator>>(istream& in, Student& s) {
        if (!(in >> s.name >> s.age >> s.avgMark)) {
            throw runtime_error("Помилка зчитування!");
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << s.name << " " << s.age << " " << s.avgMark;
        return out;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    try {
        vector<Student> students;

        ifstream fin("input.txt");
        if (!fin) {
            throw runtime_error("Неможливо відкрити файл!");
        }

        Student s;
        while (fin >> s) {
            students.push_back(s);
        }
        fin.close();

        if (students.empty()) {
            throw runtime_error("Студентів немає!");
        }

        sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) {
                return a.getMark() > b.getMark(); // за спаданням
            });

        ofstream fout("output.txt");
        if (!fout) {
            throw runtime_error("Неможливо відкрити вихідний файл!");
        }

        for (const Student& s : students) {
            fout << s << endl;
        }

        fout.close();

        cout << "Відсортовані дані записані у output.txt\n";

    } catch (exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}