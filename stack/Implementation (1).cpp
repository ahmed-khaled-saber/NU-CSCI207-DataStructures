#include <iostream>
using namespace std;

struct StackNode {
    int item;
    StackNode *next;
};

class Stack {
    StackNode *top;
public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int newItem) {
        StackNode *newPtr = new StackNode;  // Allocate a new StackNode
        if (newPtr == NULL)
            cout << "Stack push cannot allocate memory" << endl;
        else {
            newPtr->item = newItem;
            newPtr->next = top;
            top = newPtr;
        }
    }

    void pop() {
        if (isEmpty())
            cout << "Stack empty on pop" << endl;
        else {
            StackNode *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop(int &stackTop) {  // Pass stackTop by reference
        if (isEmpty())
            cout << "Stack empty on pop" << endl;
        else {
            stackTop = top->item;
            StackNode *temp = top;
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
            return top->item;
        }
    }

    void display() {
        StackNode *curPtr = top;
        cout << "\nItems in the stack: [ ";
        while (curPtr != NULL) {
            cout << curPtr->item << " ";
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
