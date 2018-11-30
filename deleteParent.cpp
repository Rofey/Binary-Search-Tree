BTNode* BinaryTree::deleteParent(BTNode *root, int element) {

	BTNode *p = root, *parent;
	while(p != 0) {
		if(element == p->data) {
			if(p->lchild == NULL) {
				parent->lchild = p->rchild;
				delete(p);
				p = NULL;
				break;
			} else {
				parent->rchild = p->lchild;
				delete(p);
				p = NULL;
				break;
			}
		} 

		else if(element < p->data) {
			parent = p;
			p = p->lchild;
		}

		else if(element > p->data) {
			parent = p;
			p = p->rchild;
		}
	}
}