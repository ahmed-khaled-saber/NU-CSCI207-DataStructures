#include <iostream>
using namespace std;

class Node {
	private:
		int value;
		Node* next;
		Node* prev;
	public:
		Node () { next = prev = NULL; }		 // default constructor
 		Node (Node* prv, int v, Node* nxt)   // parametarized constructor
	    {
	        value = v;
	        next = nxt;
	        prev = prv;
	    }
		int getValue () { return value; }
	    void setValue (int v) { value=v; }
	    
	    void  setNext (Node* n) { next = n; }
	    Node* getNext () { return next; }
	
	    void  setPrev (Node* p) { prev = p; }
	    Node* getPrev () { return prev; }
	    
};


class DoublyLinkedList{
	private:
    	Node* head;
    	Node* tail;   
    	
  	public:
	    DoublyLinkedList(){
	      head = NULL;
	      tail = NULL;
	    }
	    
	    void  setHead (Node* h) { head = h; }
	    Node* getHead () { return head; }	  
		  
	    void  setTail (Node* t) { tail = t; }
	    Node* getTail () { return tail; }
			    
	    void print(Node * here){
		  while (here != NULL){
		  	cout << here -> getValue() << '\t';
		  	here = here -> getNext();
			}
		  cout<< endl;
		}
		
		void print_from_head(){
		  Node * temp = head;			
		  while (temp != NULL){
		  	cout << temp -> getValue() << '\t';
		  	temp = temp -> getNext();
			}
		  cout<< endl;
		}
		
		void insertAtTail(int entry) {
		    
		    if (tail != NULL)
	        { 
	        	Node *newNode = new Node();
	        	newNode -> setValue(entry);
	        	
	        	tail -> setNext(newNode);
				newNode -> setPrev(tail);
				
				tail = newNode;
				 
			}
			else
			{
				head = tail = new Node(NULL ,entry, NULL);	
			} 
			
			
		}
		
		void insertAtHead(int entry) {
		    
		    if (head != NULL)
	        { 
	        	Node *newNode = new Node();
	        	newNode -> setValue(entry);
	        	
	        	newNode -> setNext(head);
	        	
	        	
	        	head -> setPrev(newNode);
	        	
	        	head = newNode;
				
				Node* temp = head;
				while (temp -> getNext() != NULL){
				  	temp = temp -> getNext();
				}
				tail = temp;				 
			}
			else
			{
				head = tail = new Node(NULL ,entry, NULL);	
			} 
			
			
		}
		
		void DeleteFromTail(){
			if (tail == NULL){
				cout << "empty Linked List";
			}
						
			tail = tail -> getPrev();
			
			delete tail -> getNext();
			
			tail -> setNext(NULL);
			
		}
		
		
		bool remove_at_position(int position){
			
            Node* tmp1 = head;
            int ListLength = 0;
            
            
            if(head == NULL){
                cout<<"List is empty"<<endl;
                return false;
            }
            
            // get the list length
            while(tmp1 != NULL){
                tmp1 = tmp1->getNext();
                ListLength++;
            }
            
            tmp1 = head;
            
            if(ListLength < position){
                cout<<"Position out of range"<<endl;
                return false;
            }
            
            //delete head
            if(position == 1){
                head = head->getNext();
//                cout<<tmp1->getValue()<<" is removed from the list"<<endl;
                delete tmp1;
                return true;
            }
            
            // access address of the node that to be deleted
            while(--position){
                tmp1 = tmp1->getNext();	
            }
            
            // delete tail
            if(tmp1 == tail){
				tmp1 -> getPrev() -> setNext(NULL);
//                cout<<tmp1->getValue()<<" is removed from the list"<<endl;
                delete tmp1;
                return true;
            }
            
            // delete another node
            tmp1 -> getPrev() -> setNext(tmp1->getNext());
            tmp1->getNext()->setPrev(tmp1 -> getPrev());
//            cout<<tmp1->getValue()<<" is removed from the list"<<endl;
            delete tmp1;
            return true;
        }
		
};

int main() {
  //create an empty LinkedList
  DoublyLinkedList DLL;

  DLL.insertAtTail(5);
  DLL.insertAtTail(7);
  DLL.insertAtTail(3);
  DLL.insertAtTail(4);
  DLL.insertAtTail(10);



  cout << "*************** Original List **********" <<endl;
  DLL.print_from_head();
  
  
  cout << "*************** delete head **********" <<endl;
  DLL.remove_at_position(1);
  DLL.print_from_head();
 
  cout << "*************** delete tail **********" <<endl;
  DLL.remove_at_position(4);
  DLL.print_from_head();
  
  cout << "*************** delete second node **********" <<endl;
  DLL.remove_at_position(2);
  DLL.print_from_head();
  
  cout << "*************** delete out of range **********" <<endl;
  DLL.remove_at_position(6);

  return 0; 
  }  
