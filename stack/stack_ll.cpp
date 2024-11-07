#include <iostream>
using namespace std;

// Node class for linked list nodes in the stack
class Node {
public:
    int data;
    Node* next;

    Node() {
        data=-1;
        next=nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    Stack() {
        top=NULL;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        // TODO: Return true if stack is empty; otherwise, false
    }

    // Function to push an element onto the stack
    void push(int data) {
        // TODO: Create a new node and push it onto the stack
        Node* newnode = new Node();
        newnode->data = data;
        newnode->next = this->top;
        this->top = newnode->next;

    }

    // Function to pop the top element from the stack and return its value
    int pop() {
        // TODO: Remove the top element and return its value
        // Important: Check if the stack is empty before popping
        
    }
};

// Function to convert a decimal number to binary
void decimalToBinary(int decimalNumber) {
    Stack stack;  // Create a stack for storing binary digits

    // Conversion logic: push remainders to the stack

    // Push remainder onto the stack



    // Display the binary number by popping all elements
    cout << "Binary: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();  // Print each binary digit
    }
    cout << endl;
}

int main() {
    int decimalNumber;

    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    decimalToBinary(decimalNumber);

    return 0;
}
