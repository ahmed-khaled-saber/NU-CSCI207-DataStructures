#include<iostream>
#include<string>
using namespace std;

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
	t.insert(t.root,13);
	t.insert(t.root,10);
	t.insert(t.root,25);
	t.insert(t.root,2);
	t.insert(t.root,12);
	t.insert(t.root,20);
	t.insert(t.root,29);
	t.insert(t.root,31);

	t.BFS();
	return 0;
}
