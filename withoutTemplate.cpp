#include <iostream>
#include <queue>
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

	public:
		BinaryTree(); 
		void insert(int d);
		void Display();
		int min(BTNode *node);
		int maximum();
		BTNode* getRoot();
		bool isBST(BTNode *Btree);
		virtual void visit(BTNode *node); 
		void breadthFirst();
		void depthFirstSearch();
		void inOrder(BTNode *p);
		void preOrder(BTNode *p);
		void postOrder(BTNode *p);
		void preOrderCall();
		void postOrderCall();
		void inOrderCall();
		int FinalHeight(BTNode *tree);
		int FinalHeightCall() { return (FinalHeight(root)); }
		void Deletion(int element);

		// Both of them deletes the leaf but the Delete() function is self implemented!
		BTNode* DeleteLeaf(BTNode *root, int element);
		BTNode* Delete(BTNode *root, int element);

		BTNode* deleteParent(BTNode *root, int element);
		~BinaryTree() {}
};


BinaryTree::BinaryTree() { 
	root = 0; 
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

//	Problem in height calculation
int BinaryTree::FinalHeight(BTNode *tree) {
	static int n = 0;
	n++;
	if(tree == 0)
		return n;
	if(tree!=0 && tree->lchild == 0) { 
		return n/2;
	}

	return (FinalHeight(tree->lchild), FinalHeight(tree->rchild));
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
	return root;
}

BTNode* BinaryTree::deleteParent(BTNode *root, int element);
	
//int BinaryTree::min(BTNode *node) {
	// BTNode *current = root, *parent;
	// while(current != 0) {
	// 	parent = current;
	// 	current = current->lchild;
	// }
	// return (parent->data);
//}

// int BinaryTree::maximum() {
// 	BTNode *current = root, *parent;
// 	while(current != 0) {
// 		parent = current;
// 		current = current->rchild;
// 	}

// 	return (parent->data);
// }

// bool isBST(BTNode *BTree) {
// 	BTNode *root = BTree;
// 	if(root == 0) {
// 		cout << "TRUE";
// 		return true;
// 	}

// 	else if(root->data > min(root->rchild)) {
// 		cout << "FALSE";
// 		return false;
// 	}

// 	else if(root->data < max(root->lchild)) {
// 		cout << "FALSE";
// 		return false;
// 	}
// 	cout << "TRUE";
// 	return true;
// }



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
	bt.insert(54);
	bt.insert(76);
	bt.insert(9);
	bt.insert(14);
	bt.insert(19);
	bt.insert(67);
	bt.insert(29);
	bt.insert(54);
	cout << "Breadth First Search: \n";
	bt.breadthFirst();
	//bt.Deletion(19);			//	Deleting a node and then displaying with depth first search  .. only deletes leaves
	bt.Delete(bt.getRoot(), 19);
	cout << endl << endl;
	cout << "Depth First Search: \n";
	bt.depthFirstSearch();
	cout << endl << endl;
	cout << "Final Height : \t";
	cout << bt.FinalHeight(bt.getRoot());		//	can call with bt.finalHeightCall() too;


	// Doesnt work for timebeing..

	//cout << bt.minimum();
	//cout << bt.maximum();
	//isBST(bt.getRoot());	
	//bt.Display();

}