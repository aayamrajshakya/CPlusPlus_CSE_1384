#include "stack.h"
#include <iostream>

Stack::Stack() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

Stack::~Stack() {
    while (size > 0) {
        remove();
    }
}

void Stack::add(char item) {
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;

    if (size == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    size++;
}

char Stack::remove() {
    if (size == 0) {
        return '\0';
    }

    Node *temp = head;
    char data = temp->data;

    head = head->next;
    delete temp;
    size--;

    return data;
}