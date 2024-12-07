#include<iostream>
#include<string>
using namespace std;
template<class T>
class Queue{
    private:
        int maxQueueSize;
        T *list;
        int qFront;
        int qRear;
        int count;
    public:
        Queue(){
            maxQueueSize = 10;
            list = new T[maxQueueSize];
            count = 0;
            qFront = 0;
            qRear = maxQueueSize - 1;
        }
        Queue(int queueSize){
            maxQueueSize = queueSize;
            list = new T[maxQueueSize];
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
        void enqueue(T new_element){
            if(isFull()){
                cout<<"Queue is Full."<<endl;
            }else{
                qRear = (qRear + 1) % maxQueueSize;
                count++;
                list[qRear] = new_element;
            }
        }
        T dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty."<<endl;
                return NULL;
            }else{
                T deleted_element = list[qFront];
                count--;
                list[qFront] = NULL;
                qFront = (qFront + 1) % maxQueueSize;
                return deleted_element;
            }
        }
        int queueSize(){
            return count;
        }
        T front(){
            if(isEmpty()){
                cout<<"Queue is Empty."<<endl;
                return INT_MIN;
            }
            return list[qFront];
        }
        T rear(){
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
    };

template<class T>
class TNode
{
public:
	T value;
	TNode<T> * Right;
	TNode<T> * Left;
	TNode(T v)
	{
		value = v;
		Right = NULL;
		Left = NULL;
	}
};

template<class T>
class BST
{
public:
	TNode<T> * root;
	int Size;

	BST()
	{
		root = NULL;
		Size = 0;
	}
	TNode<T>* insert(TNode<T> * &root, T v) //by recursion
	{
		TNode<T>* Nnode = new TNode<T>(v);
		if (root == NULL)
		{
			root = Nnode;
			Size++;
			return root;
		}
		if (v > root->value)//move right
		{
			root->Right = insert(root->Right, v);
		}
		else //move left
		{
			root->Left = insert(root->Left, v);
		}
		return root;
	}
	
	bool insert(T v)
	{
		if (root == NULL)
		{
			root = new TNode<T>(v);
			Size++;
			return true;
		}

		TNode<T> * tmp = root, *prev = NULL;
		while (tmp != NULL)
		{
			if (v < tmp->value)
			{
				prev = tmp;
				tmp = tmp->Left;
			}

			else
			{
				prev = tmp;
				tmp = tmp->Right;
			}

		}
		tmp = new TNode<T>(v);
		
		if (v > prev->value)
			prev->Right = tmp;
		else
			prev->Left = tmp;
			
		Size++;
		
		return true;
	}

	bool search(T v)
	{
		if (root == NULL)
		{
			cout << "Tree is empty" << endl;
			return false;
		}

		TNode<T> * tmp = root;
		while (tmp != NULL)
		{
			if (tmp->value == v)
			{
				cout << "Found" << endl;
				return true;
			}

			if (v < tmp->value)
			{
				tmp = tmp->Left;
			}

			else
			{
				tmp = tmp->Right;
			}

		}
		cout << "Not Found" << endl;
		return false;
	}
	bool search(TNode<T> *root,int v)
	{
		if(root == NULL)
			return false;
		if(root->value == v)
			return true;
		if(root->value > v)
			return search(root->Left,v);
		if(root->value < v)
			return search(root->Right,v);
	}
	int minValue(TNode<T> *root)
	{
	    if (root->Left == NULL)
	        return root->value;
	    return minValue(root->Left);
	}
	TNode<T> * _delete(TNode<T> *root,T v)
	{
		if(root == NULL)
			return root;
		
		if(v < root->value)
			root->Left = _delete(root->Left,v);
		else if(v > root->value)
			root->Right = _delete(root->Right,v);
		else
		{
			if(root->Left == NULL and root->Right == NULL)
				return NULL;
			else if(root->Left == NULL)
				return root->Right;
			else if(root->Right == NULL)
				return root->Left;
			int n = minValue(root);
			root->Right = _delete(root->Right,n);
			root->value = n;
			
		}
		return root;
	}
	void inorder(TNode<T> *root)
	{
		if(root == NULL)
			return;
		inorder(root->Left);
		cout<<root->value<<"	";
		inorder(root->Right);
	}
	void preorder(TNode<T> *root)
	{
		if(root == NULL)
			return;
		cout<<root->value<<"	";
		preorder(root->Left);
		preorder(root->Right);
	}
	void postorder(TNode<T> *root)
	{
		if(root == NULL)
			return;
		postorder(root->Left);
		postorder(root->Right);
		cout<<root->value<<"	";
	}
	void BFS()
	{
		Queue<TNode<T>* > q;
		q.enqueue(root);
		TNode<T> *node = NULL;
		while(q.queueSize() != 0)
		{
		  node = q.dequeue();
		  cout<<node->value<<"	";
		  if (node->Left != NULL)
			q.enqueue(node->Left);
		  if (node->Right != NULL)
			q.enqueue(node->Right);
		}
	}
	
};

int main()
{
	BST<int> t;
	t.insert(13);
	t.insert(10);
	t.insert(25);
	t.insert(2);
	t.insert(12);
	t.insert(20);
	t.insert(29);
	t.insert(31);

	t.BFS();
	return 0;
}
