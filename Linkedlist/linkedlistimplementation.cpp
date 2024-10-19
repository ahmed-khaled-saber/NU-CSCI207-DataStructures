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
    void printllist(Node* ll){
        while(ll != nullptr){
            cout<<ll->getvalue() <<endl;
            ll = ll->getnext();
        }
        cout<<"_____"<<endl;
    }

    // Insertion
    void insertafter(Node* predecessor, int value){
        Node* newnode = new Node(value, predecessor->getnext());
        predecessor->setnext(newnode);
    }

    // deletion
    void deletenode(Node* predeccesor){
        Node* toberemoved = predeccesor->getnext();
        predeccesor->setnext(toberemoved->getnext());
        delete toberemoved;
    }

    // searching
    bool searchfornodeinll(Node* ll, int v){
        while(ll!=nullptr){
            if (ll->getvalue() == v){
                return true;
            }
            else{
                ll->setnext(ll->getnext());
            }
        }
        return false;
    }

int main(){
    Node* llist = new Node(10, new Node(20, new Node(25, new Node(40, nullptr)))); 
    cout << searchfornodeinll(llist, 50) << endl;  // 0:false
    printllist(llist);

    Node* pred = llist->getnext()->getnext();  //25
    insertafter(pred, 30);
    printllist(llist);

    Node* pred_removed = llist->getnext(); //20
    deletenode(pred_removed);
    printllist(llist);

    return 0;
}