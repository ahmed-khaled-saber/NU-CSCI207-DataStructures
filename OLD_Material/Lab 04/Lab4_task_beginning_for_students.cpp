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
  
  ////////////////////////// uncomment below comments and try your function ////////////
  
//  cout << "*************** delete head **********" <<endl;
//  DLL.remove_at_position(1);
//  DLL.print_from_head();
// 
//  cout << "*************** delete tail **********" <<endl;
//  DLL.remove_at_position(4);
//  DLL.print_from_head();
//  
//  cout << "*************** delete second node **********" <<endl;
//  DLL.remove_at_position(2);
//  DLL.print_from_head();

//  cout << "*************** delete out of range **********" <<endl;
//  DLL.remove_at_position(6);


  return 0; 
  }  
