// Queue Implementation using Array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
        // You have a queue, you need to check that the elements are
        // sorted in ascending order
        // Queue: [2, 5, 7, 13, 4, 35]
        // Result: false (means that the queue elements aren't sorted in ascending order)
        
        // Your method for the task will be here
        bool sortedAscQueue(){
            // YOUR CODE WILL BE HERE
        }
};

int main() {
    Queue q;
    // Testing the queue methods
     q.enqueue(10);
     q.enqueue(15);
     q.enqueue(20);
     q.enqueue(13);
     q.enqueue(9);
     q.enqueue(27);
    // TESTING THE TASK & BONUS
     Stack s;
     q.reverseQueue(s, 3);
     q.display();
    // q.enqueue(5);
    // q.enqueue(15);
    // q.enqueue(25);
    // q.enqueue(35);
    // cout<<q.sortedAscQueue()<<endl;
    
    return 0;
}
