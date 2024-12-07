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
        top=nullptr;    // empty stack
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        // TODO: Return true if stack is empty; otherwise, false
        return this->top == nullptr
    }

    // Function to push an element onto the stack
    void push(int data) {
        // TODO: Create a new node and push it onto the stack
        Node* newNode = new Node();
        newNode->data = data;
        // stack empty
        if(isEmpty()){
            this->top = newNode;
        }else{
            newNode->next = this->top;
            this->top = newNode;
        }
    }

    // Function to pop the top element from the stack and return its value
    int pop() {
        // TODO: Remove the top element and return its value
        // Important: Check if the stack is empty before popping
        if(isEmpty()){
            cout<<"ERROR"; 
            return -1;
        }else{
            int value = this->top->data;
            Node* toberemoved = this->top;
            this->top = this->top->next;
            delete toberemoved;
            return value;
        }
    }
    int peak(){
        if(isEmpty()){
            cout<<"EMPTY!!"
            return -1;
        }else{
            return this->top->data;
        }
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


bool areBracesBalanced(string expr) {
    Stack stack;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false;  // No matching opening brace
            }
            char top = stack.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;  // Mismatched brace
            }
        }
    }


int main() {
    int decimalNumber;

    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    decimalToBinary(decimalNumber);

    return 0;
}
