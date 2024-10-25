#include <iostream>
using namespace std;

class Node{
    private:
        int value;
        Node* next;
    public:
        Node(){
            this->next = nullptr;
        }
        Node(int v, Node* n){
            this->value = v;            
            this->next = n;
        }
        int getvalue(){
            return this->value;
        }
        Node* getnext(){
            return this->next;
        }
        void setvalue(int v){
            this->value = v;

        }
        void setnext(Node* n){              
            this->next = n;

        }
};

// Traversal
void traverse(Node* head){
    while(head != nullptr){
        cout << head->getvalue() << endl;
        head = head->getnext();
    } 
}

// Insertion
void insertafter(Node* predeccessor){
    Node* newnode = new Node(30,  predeccessor->getnext());
    predeccessor->setnext(newnode);
}
// Deletion
void delete_node(Node* predeccessor){
    Node* temp = predeccessor->getnext();
    predeccessor->setnext(predeccessor->getnext()->getnext());
    temp->setnext(nullptr);
    delete temp;
}


int main(){
    Node* llist = new Node(10,
                  new Node(20,
                  new Node(25, 
                  new Node(40, nullptr)))); 
    
    insertafter(llist->getnext()->getnext());
    traverse(llist);
    delete_node(llist->getnext());
    traverse(llist);




    return 0;
}