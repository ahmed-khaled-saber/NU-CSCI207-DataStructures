#pragma once

#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int maxSize;
    int* arr;
public:
    Stack();               // Default constructor
    Stack(int initSize);   // Constructor with initial size
    void initializeStack();  // Initialize stack elements to zero
    bool isEmpty();          // Check if stack is empty
    bool isFull();           // Check if stack is full
    void push(int val);      // Push an element to the stack
    int pop();               // Pop an element from the stack
    int peek();              // Get the top element of the stack
    void clear();            // Clear the stack
    ~Stack();              // Destructor
};
