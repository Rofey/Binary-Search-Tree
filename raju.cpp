#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;

		Node()
		{
			data=0;
			left=right=0;
		}
		Node(int d)
		{
			data=d;
			left=right=0;
		}
};

class BTree
{
	public:
		Node* root;
		BTree()
		{
			root=0;
		}
		void insert(Node* t,int d);
		void visit(Node* t);
		bool isEmpty();
		void preorder(Node* t);
		void inorder(Node* t);
		void postorder(Node* t);
		void breadthfirst();
		void depthfirst();
		void iterativepreorder();
		void iterativeinorder();
		void iterativepostorder();
		void deletebymerge();
		void deletebycopy();
		bool isBST();
		
};

bool BTree::isEmpty()
{
	return(root==0);	
}

void BTree::visit(Node* t)
{
	cout<<t->data<<endl;
}

void BTree::insert(Node* t,int d)
{
	Node* curr=0;
	t=root;
	while(t!=0)
	{
		curr=t;
		if(d<curr->data)
		{
			t=t->left;
		}
		else
		{
			t=t->right;
		}
	}
	if(root==0)
	{
		root=new Node(d);
	}
	else if(d<curr->data)
	{
		curr->left=new Node(d);
	}
	else
	{
		curr->right=new Node(d);
	}
}

void BTree::preorder(Node* t)
{
	if(t!=0)
	{
		visit(t);
		preorder(t->left);
		preorder(t->right);	
	}	
}

void BTree::inorder(Node* t)
{
	if(t!=0)
	{
		inorder(t->left);
		visit(t);
		inorder(t->right);
	}
}

void BTree::postorder(Node* t)
{
	if(t!=0)
		{
			postorder(t->left);
			postorder(t->right);
			visit(t);
		}	
}



int main()
{
	BTree B;
	Node* rt=NULL;
	B.insert(rt,2);
	B.insert(rt,3);
	B.insert(rt,1);
	B.insert(rt,4);
	B.insert(rt,5);
	B.inorder(rt);
}