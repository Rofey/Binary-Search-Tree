#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class BTNode {
	public:
		int data;
		BTNode *lchild;
		BTNode *rchild;

	public:
		BTNode() : data(0), lchild(0), rchild(0) {}
		BTNode(int d, BTNode *l = 0 , BTNode *r = 0);
		BTNode* getLeft() {return lchild; }


};

BTNode::BTNode(int d,  BTNode *l , BTNode *r ) {
	data = d;
	lchild = l;
	rchild = r;
} 



class BinaryTree {
	private:
		BTNode *root;
		int size;

	public:
		BinaryTree(); 
		void insert(int d);
		void Display();
		int min(BTNode *node);
		int max(BTNode *node);
		BTNode* getRoot();
		bool isBST(BTNode *node);
		virtual void visit(BTNode *node); 
		void breadthFirst();
		void depthFirstSearch();
		void inOrder(BTNode *p);
		void preOrder(BTNode *p);
		void postOrder(BTNode *p);
		void preOrderCall();
		void postOrderCall();
		void inOrderCall();
		void Deletion(int element);
		int utilizeBothNodes(BTNode *p);
		int getHeight(BTNode *root);
		int maxa(int a, int b);


		// Both of them deletes the leaf but the Delete() function is self implemented!
		BTNode* DeleteLeaf(BTNode *root, int element);
		BTNode* Delete(BTNode *root, int element);
		void deleteByCopying(BTNode *&node);

		BTNode* deleteParent(BTNode *root, int element);
		~BinaryTree() {}
};


BinaryTree::BinaryTree() { 
	root = 0; 
	size = 0;
}

BTNode* BinaryTree::getRoot() {
	return root;
}

void BinaryTree::insert(int d) {
	BTNode *p = root, *prev = 0;
	while(p != 0) {
		prev = p;
		if(d < p->data)
			p = p->lchild;
		else p = p->rchild;

	}
	size++;

	if(root == 0) 
		root = new BTNode(d);
	else if(d < prev->data)
		prev->lchild = new BTNode(d);
	else prev->rchild = new BTNode(d);
}

void BinaryTree::visit(BTNode *node) {
	cout << node->data << " ";
}

void BinaryTree::breadthFirst() {
	BTNode *p = root;
	queue<BTNode *> queue;
	if(p != 0) {
		queue.push(p);
		while(!queue.empty()) {
			p = queue.front();
			queue.pop();
			visit(p);
			if(p->lchild != 0)
				queue.push(p->lchild);
			if(p->rchild != 0 )
				queue.push(p->rchild);
		}
	}
}

void BinaryTree::inOrderCall() {
	inOrder(root);
}

void BinaryTree::preOrderCall() {
	preOrder(root);
}

void BinaryTree::postOrderCall() {
	postOrder(root);
}

void BinaryTree::inOrder(BTNode *p) {
	if(p != 0) {
		inOrder(p->lchild);
		visit(p);
		inOrder(p->rchild);
	}
}

void BinaryTree::preOrder(BTNode *p) {
	if(p != 0) {
		visit(p);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
	
}

void BinaryTree::postOrder(BTNode *p) {
	if(p != 0) {
		postOrder(p->lchild);
		postOrder(p->rchild);
		visit(p);
	}
	
}

void BinaryTree::depthFirstSearch() {
	cout << "In Order: \n";
	inOrder(root);
	cout << endl << endl;

	cout << "Pre Order: \n";
	preOrder(root);
	cout << endl << endl;

	cout << "post Order: \n";
	postOrder(root);
	cout << endl << endl;
}

void BinaryTree::Deletion(int element) {
	DeleteLeaf(root, element);

}

BTNode* BinaryTree::DeleteLeaf(BTNode *root, int element) {
	if(root==NULL) {
		return NULL;
	}
	root->lchild = DeleteLeaf(root->lchild, element);
	root->rchild = DeleteLeaf(root->rchild, element);

	if(root->data == element && root->lchild == NULL && root->rchild == NULL) {
		delete(root);
		return NULL;
	}
	return root;
}


// root pointer is sent to this function and
// it deletes using recursion.
// Second implementation of the above one, used
// Two different ways
BTNode* BinaryTree::Delete(BTNode *root, int element) {
	BTNode *p = root;
	if(element == root->data) {
		delete(root);
		root = NULL;
	}
	else if(element < root->data) {
		p = Delete(p->lchild, element);
	} 

	else if(element > root->data) {
		p = Delete(p->rchild, element);
	}
	return 	root;
}

	
int BinaryTree::min(BTNode *node) {
	BTNode *current = root, *parent;
	while(current != 0) {
		parent = current;
		current = current->lchild;
	}
	return (parent->data);
}

int BinaryTree::max(BTNode *node) {
	BTNode *current = root, *parent;
	while(current != 0) {
		parent = current;
		current = current->rchild;
	}

	return (parent->data);
}

int BinaryTree::utilizeBothNodes(BTNode *p) {
	static int count = 0;

	if(p->lchild != NULL || p->rchild != NULL) {
		count++;
		utilizeBothNodes(p->lchild);
		utilizeBothNodes(p->rchild);
	}
	return count;
}

bool BinaryTree::isBST(BTNode *node) {
	if(node == NULL) 
		return true;
	if(node->lchild != NULL && node->data > max(node))
		return false;
	if(node->rchild != NULL && node->data < min(node))
		return false;
	if(!isBST(node->lchild) || !isBST(node->rchild))
		return false;

	return true;
}

int BinaryTree::maxa(int a, int b) {
	return ((a>b)? a : b);
}


int BinaryTree::getHeight(BTNode *root) {
	if(root == NULL)
		return 0;

	int lh = getHeight(root->lchild);
	int rh = getHeight(root->rchild);

	return 1 + maxa(lh, rh);
}

void BinaryTree::deleteByCopying(BTNode *&node) {
	BTNode *tmp, *prev, *curr;
	if(node->lchild == NULL)
		node = node->rchild;
	if(node->rchild == NULL)
		node = node->lchild;
	else {
		tmp = node->lchild;
		prev = node;
		while(tmp->rchild != NULL) {
			prev = tmp;
			tmp = tmp->rchild;
		}
		node->data = tmp->data;

		if(prev == node) 
			prev->lchild = tmp->lchild;
		else
			prev->rchild = tmp->rchild;

	}



}



void BinaryTree::Display() {
	BTNode *current = root;
	while(current != 0) {
		cout << current->data << " ";
		current = current->lchild;
	}
}	


int main() {
	BinaryTree bt;
	bt.insert(50);
	bt.insert(17);
	bt.insert(72);
	bt.insert(12);
	bt.insert(23);
	//bt.insert(54);
	bt.insert(76);
	bt.insert(9);
	bt.insert(14);
	bt.insert(19);
	bt.insert(67);
	bt.insert(29);
	

	cout << "Breadth First Search: \n";
	bt.breadthFirst();
	
	//All three functions work!

	//bt.Deletion(29);			//	Deleting a node and then displaying with depth first search  .. only deletes leaves
	//bt.Delete(bt.getRoot(), 19);
	//bt.deleteParent(bt.getRoot(), 14);

	BTNode *x = &(bt.getRoot());
	bt.deleteByCopying(x);

	cout << endl << endl;
	cout << "Depth First Search: \n";
	bt.depthFirstSearch();
	
	cout << endl << endl;
	cout << "Final Height : \t";
	cout << bt.getHeight(bt.getRoot());		//	can call with bt.finalHeightCall() too;
	cout << endl << "Minimum: " << bt.min(bt.getRoot());
	cout << endl << "Maximum: " << bt.max(bt.getRoot());


	bool check = bt.isBST(bt.getRoot());
	check ? cout << "\nIt is a BST": cout << "\nNot a BST";

	//cout << endl << "Parents that utilize both parents: " << bt.utilizeBothNodes(bt.getRoot());
	//^ This function doesnt work with deletion!


	
}