#include <iostream>
using namespace std;

class Node
{
    private:
        int value;
        Node* next;
        Node* prev;
    public:
        Node() : next(nullptr), prev(nullptr) {}
        Node(Node* prv, int v, Node* nxt) : value(v), prev(prv), next(nxt) {}
        
        ~Node() { cout << "Deleting node with value: " << value << endl; }
        
        int getValue() { return this->value; }
        void setValue(int v) { this->value = v; }
        
        Node* getNext() { return this->next; }
        void setNext(Node* n) { this->next = n; }
        
        Node* getPrev() { return this->prev; }
        void setPrev(Node* prev) { this->prev = prev; }
};

class Dll
{
private:
    Node* head;
    Node* tail;
public:
    Dll() : head(nullptr), tail(nullptr) {} // Empty

    void setHead(Node* h) { this->head = h; }
    void setTail(Node* t) { this->tail = t; }
    Node* getHead() { return this->head; }
    Node* getTail() { return this->tail; }

    void print_from_head() {
        Node* tmp = this->head;
        while (tmp != nullptr) {
            cout << tmp->getValue() << " ";
            tmp = tmp->getNext();
        }
        cout << endl;
    }

    void insertAtTail(int v) {
        Node* newNode = new Node(nullptr, v, nullptr);
        if (this->tail != nullptr) {
            newNode->setPrev(this->tail);
            this->tail->setNext(newNode);
            this->tail = newNode;
        } else {
            this->tail = this->head = newNode;
        }
    }

    void deleteAtTail() {
        if (this->tail == nullptr) {
            cout << "The List is EMPTY !!!" << endl;
            return;
        } else if (this->tail == this->head) { // Only one node
            delete this->tail;
            this->tail = this->head = nullptr;
        } else {
            Node* temp = this->tail;
            this->tail = this->tail->getPrev();
            this->tail->setNext(nullptr);
            delete temp;
        }
    }

    int length() {
        int l = 0;
        Node* tmp = this->head;
        while (tmp != nullptr) {
            l++;
            tmp = tmp->getNext();
        }
        return l;
    }

    bool isEmpty() {
        return this->head == nullptr && this->tail == nullptr;
    }

    void deleteAtHead() {
        if (this->head == nullptr) {
            cout << "The List is EMPTY !!!" << endl;
            return;
        }
        Node* temp = this->head;
        if (this->head == this->tail) { // Only one node
            this->head = this->tail = nullptr;
        } else {
            this->head = this->head->getNext();
            this->head->setPrev(nullptr);
        }
        delete temp;
    }

    void insertAtHead(int v) {
        Node* newNode = new Node(nullptr, v, this->head);
        if (this->head != nullptr) {
            this->head->setPrev(newNode);
        }
        this->head = newNode;
        if (this->tail == nullptr) {
            this->tail = newNode;
        }
    }

    void removeAtPosition(int position) {
        if (this->isEmpty()) {
            cout << "List is EMPTY !!!" << endl;
            return;
        } else if (this->length() < position) {
            cout << "Position out of range" << endl;
            return;
        } else if (position == 1) {
            this->deleteAtHead();
        } else if (position == this->length()) {
            this->deleteAtTail();
        } else {
            Node* tmp = this->head;
            for (int i = 1; i < position; ++i) {
                tmp = tmp->getNext();
            }
            tmp->getPrev()->setNext(tmp->getNext());
            tmp->getNext()->setPrev(tmp->getPrev());
            delete tmp;
        }
    }

    ~Dll() {
        while (head != nullptr) {
            deleteAtHead();
        }
    }
};
    
int main() {
    Dll dll;

    // Testing insertion and printing
    dll.insertAtHead(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    
    dll.print_from_head();
    cout << "========\n";
    
    // Testing deletion at tail
    dll.deleteAtTail();
    dll.print_from_head();
    cout << "========\n";
    
    // Testing removal by position
    dll.removeAtPosition(1);
    dll.print_from_head();
    cout << "========\n";
    
    // Final length of the list
    cout << "Length of list: " << dll.length() << endl;
    
    return 0;
}
