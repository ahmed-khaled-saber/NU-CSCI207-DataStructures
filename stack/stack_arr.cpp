#include <iostream>
using namespace std;

class myStack {
private:
    int top;
    int maxSize;
    int* arr;

public:
    // Default constructor with default size 100
    myStack() : myStack(100) {}

    // Constructor with a specified size
    myStack(int initSize) {
        this->maxSize = initSize;
        this->top = -1;
        this->arr = new int[this->maxSize];
    }

    // Initialize stack (if needed)
    void initializeStack() {
        for (int i = 0; i < this->maxSize; i++) {
            this->arr[i] = 0;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return this->top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return this->top == this->maxSize - 1;
    }

    // Push element onto stack
    void push(int val) {
        if (this->isFull()) {
            cout << "Stack Overflow! Cannot push value " << val << endl;
        } else {
            this->arr[++this->top] = val;
        }
    }

    // Pop element from stack
    int pop() {
        if (this->isEmpty()) {
            cout << "Stack Underflow! Cannot pop value" << endl;
            return -1;
        } else {
            return this->arr[this->top--];
        }
    }

    // Peek at the top element
    int peek() {
        if (this->isEmpty()) {
            cout << "Stack is empty! Cannot peek value" << endl;
            return -1;
        } else {
            return this->arr[this->top];
        }
    }

    // Clear stack
    void clear() {
        this->top = -1;
        cout << "Stack has been cleared." << endl;
    }

    // Destructor to free memory
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
