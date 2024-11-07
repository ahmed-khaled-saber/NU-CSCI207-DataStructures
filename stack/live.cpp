#include <iostream>
using namespace std;

class myStack {
private:
    int top;
    int maxSize;
    int* arr;

public:
    myStack() : myStack(100) {}

    myStack(int initSize) {
        this->maxSize = initSize;
        this->top = -1;
        this->arr = new int[this->maxSize];
    }

    void initializeStack() {
        for (int i = 0; i < this->maxSize; i++) {
            this->arr[i] = 0;
        }
    }

    bool isEmpty() {
        return this->top == -1;
    }

    bool isFull() {
        return this->top == this->maxSize - 1;
    }

    void push(int val) {
        if (this->isFull()) {
            cout << "Stack Overflow! Cannot push value " << val << endl;
        } else {
            this->arr[++this->top] = val;
        }
    }

    int pop() {
        if (this->isEmpty()) {
            cout << "Stack Underflow! Cannot pop value" << endl;
            return -1;
        } else {
            return this->arr[this->top--];
        }
    }

    int peek() {
        if (this->isEmpty()) {
            cout << "Stack is empty! Cannot peek value" << endl;
            return -1;
        } else {
            return this->arr[this->top];
        }
    }

    void clear() {
        this->top = -1;
        cout << "Stack has been cleared." << endl;
    }

    ~myStack() {
        delete[] arr;
    }
};

int main() {
    myStack stck(10);
    stck.push(5);
    stck.push(8);
    stck.pop();
    stck.push(10);
    cout << "Top element is: " << stck.peek() << endl;
    stck.clear();

    return 0;
}
