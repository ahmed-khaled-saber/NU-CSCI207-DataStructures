#include "Stack.h"

Stack::Stack() : Stack(100) {}

Stack::Stack(int initSize) {
    this->maxSize = initSize;
    this->top = -1;
    this->arr = new int[this->maxSize];
}

void Stack::initializeStack() {
    for (int i = 0; i < this->maxSize; i++) {
        this->arr[i] = 0;
    }
}

bool Stack::isEmpty() {
    return this->top == -1;
}

bool Stack::isFull() {
    return this->top == this->maxSize - 1;
}

void Stack::push(int val) {
    if (this->isFull()) {
        cout << "Stack Overflow! Cannot push value " << val << endl;
    } else {
        this->arr[++this->top] = val;
    }
}

int Stack::pop() {
    if (this->isEmpty()) {
        cout << "Stack Underflow! Cannot pop value" << endl;
        return -1;
    } else {
        return this->arr[this->top--];
    }
}

int Stack::peek() {
    if (this->isEmpty()) {
        cout << "Stack is empty! Cannot peek value" << endl;
        return -1;
    } else {
        return this->arr[this->top];
    }
}

void Stack::clear() {
    this->top = -1;
    cout << "Stack has been cleared." << endl;
}

Stack::~Stack() {
    delete[] arr;
}
