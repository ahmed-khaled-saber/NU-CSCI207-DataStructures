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
            this->maxSize = 5;
            this->arr = new int[this->maxSize];
            this->front=0; this->rear= this->maxSize-1;
            this->count=0;
        }
        void reset_Q(){
            for (int i = 0; i < this->maxSize; i++)
            {
                this->arr[i] = 0;   //null
            }
            this->front=0; this->rear= this->maxSize-1;
            this->count=0;
        }
        bool is_empty(){
            return count == 0;
        }
        bool is_full(){
            return count == this->maxSize;
        }
        int get_front(){
            assert(!this->is_empty()); 
            return this->arr[this->front];
        }
        int get_back(){
            assert(!this->is_empty()); 
            return this->arr[this->rear];
        }
        void enque(int v){
            if(this->is_full()){
                cout << "Q is FULL \n";
            }else{
                this->rear = (this->rear + 1) % this->maxSize;  // circular effect
                this->arr[this->rear] = v;
                this->count++;
            }
        }
        void dequeue(){
            if(this->is_empty()){
                cout<<"Q is EMPTY! \n";
            }else{
                this->arr[front] = 0;   // we do not have to !
                this->front = (this->front + 1) % this->maxSize;
                this->count--;
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