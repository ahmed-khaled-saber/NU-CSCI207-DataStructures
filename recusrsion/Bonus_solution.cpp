#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next; 
        Node(){
            value = 0;
            next = NULL;
        }
        Node(int v){
            this->value = v;
            this->next = NULL;
        }
};
class LinkedList{
    
    public:
    	Node *head;
        LinkedList(){ head= NULL; }
        bool insert(int value){
            Node *newNode = new Node(value);
            if(head == NULL){
                head = newNode;
                cout<<head->value<<" is added to the list"<<endl;
                return true;
            }
            Node* tmp = head;
            while(tmp-> next != NULL){
                tmp = tmp->next;
            }
            tmp->next = newNode;
            cout<<value<<" is added to the list"<<endl;
            return true;
        }
        
		void display()
		{ 
            cout<<"List items: "<<endl; 
            Node* tmp = head; 
            if(head == NULL){ 
                cout<<"List is empty"<<endl; 
            } 
            while(tmp != NULL){ 
                cout<<tmp->value<<" "; 
                tmp = tmp->next; 
            } 
            cout<<endl; 
    	}
};

bool F(Node *head, int start, int end, int K)
{	
	int Mid = (start + end) / 2;
	Node *tmp = head;
	for(int i = 0;i<Mid;i++)
	{
		tmp = tmp->next;
	}
	int Sum = tmp->value +tmp->next->value;
	if(Mid == start && Sum < K)
		return false;
	if(Mid == end && Sum > K)
		return false;
	if(Sum == K)
		return true;
	else if(Sum > K)
		F(head,start,Mid,K);
	else
		F(head,Mid,end,K);
}
int main() {
    LinkedList ll;
    ll.insert(6);
    ll.insert(8);
    ll.insert(9);
    ll.insert(10);
    ll.insert(11);
    ll.insert(15);
    int K = 17;
    cout<<"F = "<<F(ll.head,0,5,K);
    return 0;
}
