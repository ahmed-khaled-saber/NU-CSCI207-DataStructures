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
        bool remove_from_position(int position){
            // Position starts from 1
            Node* tmp1 = head;
            Node* tmp2 = NULL;
            int ListLength = 0;
            if(head == NULL){
                cout<<"List is empty"<<endl;
                return false;
            }
            while(tmp1 != NULL){
                tmp1 = tmp1->next;
                ListLength++;
            }
            tmp1 = head;
            if(ListLength < position){
                cout<<"Position out of range"<<endl;
                return false;
            }
            if(position = 1){
                head = head->next;
                delete tmp1;
                cout<<head->value<<" is removed from the list"<<endl;
                return true;
            }
            while(position-- > 1){
                tmp2 = tmp1;
                tmp1 = tmp1->next;
            }
            tmp2->next = tmp1->next;
            delete tmp1;
            cout<<tmp1->value<<" is removed from the list"<<endl;
            return true;
        }
        void ReplaceAll(int oldvalue, int newvalue)
			{
			       if(head == NULL){
			                cout<<"List is empty"<<endl;
			            }
			        else
			        {
			        	Node* tmp;
			        	tmp = head;
			            while(tmp !=NULL)
			            {
			            	if(tmp->value == oldvalue)
			            		tmp->value = newvalue;
						}
			
			        }
			}
		bool insert_before_position(int value, int position, Node* head){
		    Node *newNode = new Node(value);
		    Node* tmp1 = head;
		    Node* tmp2 = NULL;
		    int ListLength = 0;
		    if(head == NULL){
		        head = newNode;
		        cout<<value<<" is added to the list"<<endl;
		        return true;
		    }
		    while(tmp1 != NULL){
		        tmp1 = tmp1->next;
		        ListLength++;
		    }
		    tmp1 = head;
		    if(ListLength < position){
		        cout<<"Position out of range"<<endl;
		        return false;
		    }
		    if(position == 1){
		    	newNode->next = this->head;
				this->head = newNode;
		        //newNode = tmp1;
		        cout<<value<<" is added to the list"<<endl;
		        return true;
		    }
		    while(position-- > 1){
		        tmp2 = tmp1;
		        tmp1 = tmp1->next;
		    }
		    newNode->next = tmp1;
		    tmp2->next = newNode;
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
int main() {
    LinkedList ll;
    ll.insert(56);
    ll.insert(23);
    ll.insert(4);
    ll.insert(2);
    ll.insert_before_position(90,1,ll.head);
    ll.display();
    return 0;
}
