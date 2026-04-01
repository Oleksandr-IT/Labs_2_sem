#pragma once
using namespace std;

// Клас елемента стеку
class Node {
public:
    char data;
    Node* next;

    Node(char ch) {
        data = ch;
        next = nullptr;
    }
};

// Клас стеку
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char ch) {
        Node* newNode = new Node(ch);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    char peek() {
        if (top != nullptr)
            return top->data;
        return '\0';
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty())
            pop();
    }
};

#ifndef LABS_2_SEM_LAB2_1_H
#define LABS_2_SEM_LAB2_1_H

#endif //LABS_2_SEM_LAB2_1_H
