#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

class Stack {
    Node *top;
public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int newvalue) {
        Node *newNode = new Node;  // Allocate a new Node
        if (newNode == nullptr)
            cout << "Stack push cannot allocate memory" << endl;
        else {
            newNode->value = newvalue;
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (isEmpty())
            cout << "Stack empty on pop" << endl;
        else {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop(int &stackTop) {  // Pass stackTop by reference
        if (isEmpty())
            cout << "Stack empty on pop" << endl;
        else {
            stackTop = top->value;
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    int Peek() {
        if (isEmpty()) {
            cout << "Stack empty on getTop" << endl;
            return -1;  // Return -1 or any other sentinel value for empty stack
        } else {
            return top->value;
        }
    }

    void display() {
        Node *curPtr = top;
        cout << "\nvalues in the stack: [ ";
        while (curPtr != NULL) {
            cout << curPtr->value << " ";
            curPtr = curPtr->next;
        }
        cout << "]\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(120);
    s.pop();
    s.display();
    return 0;
}
