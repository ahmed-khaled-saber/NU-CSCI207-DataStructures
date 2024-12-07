// an Array Implementation of a Queue Datastructure | Circular Implementation
#include <cassert>
#include <iostream>
using namespace std;

class Queue{
    private:
        int* arr;
        int front;
        int rear;
        int count;
        int maxSize;

    public:
        Queue(){
            front = -1; rear = -1;
            count = 0;
            maxSize = 5; 
            arr = new int[maxSize];
        }
        void reset_Q(){
        }
        bool is_empty(){
            return count == 0;
        }
        bool is_full(){
            return count == maxSize;
        }
        int get_front(){
            return arr[front];
        }
        int get_back(){
            return arr[rear];
        }
        void enque(int v){
            if(is_full()){
                cout << "FULL Q";
            }
            else{
                back = (back + 1) % maxSize;
                arr[back] = v;
                count++;
            }
        }
        void dequeue(){
            if(is_empty()){
                cout<<"EMPTY Q";
            }else{
                // arr[front] = 0;
                front = (front + 1)%maxSize;
                count--;
            }
            
        }
        ~Queue(){
            delete[] this->arr; 
        }
        // TASK::TODO
        

};

int main(){ 
    Queue* Q = new Queue();
    // 
    Q->enque(1);
    Q->enque(2);
    Q->enque(3);
    // 
    Q->dequeue();
    // 
    cout << "Q front:: " << Q->get_front() << endl;
    cout << "Q back::  " << Q->get_back()  << endl;
    // 
    delete Q;
    // 
    return 0;
}