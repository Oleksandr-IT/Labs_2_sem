#pragma once

#ifndef LABS_2_SEM_LAB2_3_H
#define LABS_2_SEM_LAB2_3_H

using namespace std;

class GardenTree {
protected:
    static int counter;   // лічильник дерев
    int number;           // номер дерева
    int age;              // вік
    bool fruiting;        // плодоношення

public:
    GardenTree(int a, bool f) {
        if (a < 0)
            throw invalid_argument("Вік не може бути від'ємним!");

        number = ++counter;
        age = a;
        fruiting = f;
    }

    virtual void show() {
        cout << "Дерево №" << number
             << ", вік: " << age
             << ", плодоношення: "
             << (fruiting ? "так" : "ні") << endl;
    }

    virtual void transplantDecision() {
        if (age < 5 && !fruiting)
            cout << "Рекомендується пересадка.\n";
        else
            cout << "Пересадка не потрібна.\n";
    }

    virtual ~GardenTree() {}
};

int GardenTree::counter = 0;

// Похідний клас Яблуня
class AppleTree : public GardenTree {
public:
    AppleTree(int a, bool f) : GardenTree(a, f) {}

    void show() override {
        cout << "Яблуня -> ";
        GardenTree::show();
    }
};

// Похідний клас Вишня
class CherryTree : public GardenTree {
public:
    CherryTree(int a, bool f) : GardenTree(a, f) {}

    void show() override {
        cout << "Вишня -> ";
        GardenTree::show();
    }
};

// Похідний клас Груша
class PearTree : public GardenTree {
public:
    PearTree(int a, bool f) : GardenTree(a, f) {}

    void show() override {
        cout << "Груша -> ";
        GardenTree::show();
    }
};

#endif //LABS_2_SEM_LAB2_3_H