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
    Dll() : head(nullptr), tail(nullptr) {}

    void setHead(Node* h) { this->head = h; }
    void setTail(Node* t) { this->tail = t; }

    Node* getHead() { return this->head; }
    Node* getTail() { return this->tail; }

    void print_from_head() {
        Node* tmp = this->head;
        while(this->tmp != nullptr){
            cout << this->tmp->getValue() << endl;
            this->tmp = this->tmp->getNext();
        }
    };


    void insertAtTail(int v) {
        Node* newNode = new Node(nullptr, v, nullptr);
        if (this->tail != nullptr) {
            this->tail->setNext(newNode);
            newNode->setPrev(this->tail);
            this->tail = newNode;
        }
        else{ // list is empty
            
            this->head = this->tail = newNode;
        }
    };
    void deleteAtTail(){
        if (this->tail == nullptr) {
            cout<<"list is EMPTY !!!"<<end;
        }
        else if (this->tail == this->head) { // the list has one element
            Node* toberemoved = this->tail;
            this->head = this->tail = nullptr;
            delete toberemoved;
        }
        else {
            Node* toberemoved = this->tail;
            this->tail = this->tail->getPrev();
            delete toberemoved;
        }
    };
    int length() {

    };
    bool isEmpty() {};
    void deleteAtHead() {};
    void insertAtHead(int v) {};




    void removeAtPosition(int position) {
        if (this->isEmpty()) {
            cout<<"msg " << endl;
        } 
        else if (this->length() < position) {
            cout << "you running out of size" << endl;
        }
        else if (position == 1) {
            this->deleteAtHead();
        }
        else if (position == this->length()) {
            this->deleteAtTail();
        }
        else {
            Node* tmp = this->head();
            for(int i = 0; i<position; i++){
                tmp = tmp->getNext();
            }
            Node* toberemoved = tmp;
            tmp->getPrev = tmp->getNext();
            tmp->getNext()->setPrev(tmp->getPrev());
            delete toberemoved;
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

    // insertion and printing
    dll.insertAtTail(1);
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
