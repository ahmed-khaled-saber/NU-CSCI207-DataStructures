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
        StackNode *newPtr = new StackNode;
        if (newPtr == NULL) {
            cout << "Stack push cannot allocate memory" << endl;
        } else {
            newPtr->item = newItem;
            newPtr->next = top;
            top = newPtr;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack empty on pop" << endl;
            return -1;
        } else {
            StackNode *temp = top;
            int poppedItem = top->item;
            top = top->next;
            temp->next = NULL;
            delete temp;
            return poppedItem;
        }
    }
};

// Function to convert a decimal number to binary using Stack
void decimalToBinary(int decimal) {
    Stack s;
    while (decimal > 0) {
        int remainder = decimal % 2;
        s.push(remainder);
        decimal /= 2;
    }

    cout << "Binary: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;
    decimalToBinary(decimal);
    return 0;
}
