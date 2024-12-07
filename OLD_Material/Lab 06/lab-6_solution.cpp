// Queue Implementation using Array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack
{
	private:
    	int maxStackSize;
    	int stackTop;
    	int *list;
	public:
	    Stack() 
		{
		    maxStackSize = 100;
		    stackTop = -1; //set stackTop to -1
		    //create the array
		    list = new int[maxStackSize]; 
		}
	    Stack(int S) 
		{
		    maxStackSize = S;
		    stackTop = -1; //set stackTop to -1
		    //create the array
		    list = new int[maxStackSize]; 
		}
		bool isEmptyStack()
		{
	    	return (stackTop == -1);
		}
		bool isFullStack() 
		{
	    	return (stackTop == (maxStackSize-1));
		}
		void push(int newItem) 
		{
		    if (isFullStack())
			{
		        cout << "Cannot add->the stack is full" << endl;
				  return;
			}
			stackTop++;          //increment stackTop
		 	list[stackTop] = newItem; //add newItem 
		}
		int pop()
		{
		    if (isEmptyStack())
			  {
				cout << "The stack is empty !!!" << endl;
				return -1;
		    }
			  return list[stackTop--];
		}
		int peek()
		{
			if (isEmptyStack())
			{
				cout << "The stack is empty !!!" << endl;
		    }
		    else{
		        return list[stackTop];
		    }
		}
		void clear()
		{
			if (isEmptyStack())
			{
				cout << "The stack is empty !!!" << endl;
		    }
			while(!isEmptyStack())
			{
				pop();
			}
		}
};

class Queue{
    private:
        int maxQueueSize;
        int *list;
        int qFront;
        int qRear;
        int count;
    public:
        Queue(){
            maxQueueSize = 10;
            list = new int[maxQueueSize];
            count = 0;
            qFront = 0;
            qRear = maxQueueSize - 1;
        }
        Queue(int queueSize){
            maxQueueSize = queueSize;
            list = new int[maxQueueSize];
            count = 0;
            qFront = 0;
            qRear = maxQueueSize - 1;
        }
        
        // Queue Operations
        // enqueue(), dequeue(), queueSize(), front(), rear(), display(), isFull(), isEmpty()
        
        bool isFull(){
            return (count == maxQueueSize);
        }
        bool isEmpty(){
            return (count == 0);
        }
        void enqueue(int new_element){
            if(isFull()){
                cout<<"Queue is Full."<<endl;
            }else{
                qRear = (qRear + 1) % maxQueueSize;
                count++;
                list[qRear] = new_element;
            }
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty."<<endl;
                return INT_MIN;
            }else{
                int deleted_element = list[qFront];
                count--;
                list[qFront] = INT_MIN;
                qFront = (qFront + 1) % maxQueueSize;
                return deleted_element;
            }
        }
        int queueSize(){
            return count;
        }
        int front(){
            if(isEmpty()){
                cout<<"Queue is Empty."<<endl;
                return INT_MIN;
            }
            return list[qFront];
        }
        int rear(){
            if(isEmpty()){
                cout<<"Queue is Empty."<<endl;
                return INT_MIN;
            }
            return list[qRear];
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue is Empty."<<endl;
            }else{
                while(!isEmpty()){
                    cout<<dequeue()<<endl;
                }
            }
        }
        // Task
        // You have a queue with elements
        // Your task is to reverse the queue using a stack, the final queue should 
        // contain only elements divisible by k and each element should be greater than 
        // the front value.
        // TEST CASE:
        // Queue: [10, 15, 20, 13, 9, 27]
        // Result: [27, 15]
        
        // Your method for the task will be here
        void reverseQueue(Stack s, int k){
            int f_value = front();
            int v = INT_MIN;
            while(!isEmpty()){
                v = dequeue();
                if(v%k == 0 && v > f_value)
                    s.push(v);
            }
            while(!s.isEmptyStack()){
                enqueue(s.pop());
            }
        }
        // Bonus
        // You have a queue, you need to check that the elements are
        // sorted in ascending order
        // TEST CASE:
        // Queue: [2, 5, 7, 13, 4, 35]
        // Result: false (means that the queue elements aren't sorted in ascending order)
        
        // Your method for the bonus will be here
        bool sortedAscQueue(){
            int tmp = INT_MIN;
            int tmp2 = INT_MIN;
            bool result = true;
            while(!isEmpty()){
                tmp2 = dequeue();
                if(tmp2 > tmp){
                    result = true;
                    tmp = tmp2;
                }else{
                    return false;
                }
            }
            return result;
        }
};

int main() {
    Queue q;
    // TESTING THE TASK & BONUS
    // q.enqueue(10);
    // q.enqueue(15);
    // q.enqueue(20);
    // q.enqueue(13);
    // q.enqueue(9);
    // q.enqueue(27);
    // TASK
    // Stack s;
    // int k = 3;
    // q.reverseQueue(s, k);
    // q.display();
    // BONUS
    // q.enqueue(5);
    // q.enqueue(15);
    // q.enqueue(25);
    // q.enqueue(35);
    // cout<<q.sortedAscQueue()<<endl;
    
    return 0;
}
