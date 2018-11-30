#include <iostream>
using namespace std;

template <class T>
class BTNode {
	private:
		T data;
		BTNode<T> *lchild;
		BTNode<T> *rchild;

	public:
		BTNode() : data(0), lchild(0), rchild(0) {}
		BTNode(T d, BTNode<T> *l , BTNode<T> *r);
		BTNode<T>* getLeft() {return lchild; }


};

template <class T>
BTNode<T>::BTNode(T d,  BTNode<T> *l , BTNode<T> *r ) {
	data = d;
	*lchild = *l;
	*rchild = *r;
} 



template <class T>
class BinaryTree {
	private:
		BTNode<T> *root;

	public:
		BinaryTree() : root(0) {}
		BinaryTree(BTNode<T> *r = 0) { *root = *r; } 
		void insert(T d);
		//BTNode* GetNewNode(T data);
		void Display();


};

// template <class T>
// BTNode* BinaryTree<T>::GetNewNode(T data) {
// 	BTNode *newNode = new BTNode();
// 	newNode->data = data;
// 	newNode->left = newNode->right = NULL;
// 	return newNode;
// }


template <class T>
void BinaryTree<T> :: insert(T d) {
	if(root == NULL) {
		//root = new BTNode();
		root->data = d;
		root->left = NULL;
		root->right = NULL;
		cout << "Root added";
	}
}

template <class T>
void BinaryTree<T> ::Display() {
	BTNode<T> current = root;
	while(current != 0) {
		cout << current->data;
	}
}




int main() {
	BinaryTree<int> ;
	bt.insert(4);


}