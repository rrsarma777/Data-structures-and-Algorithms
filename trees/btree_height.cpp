#include <iostream>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left = NULL;
	BSTNode* right = NULL;
};

BSTNode* Insert(BSTNode* Node, int data) {
	BSTNode* e = new BSTNode();
	e->data = data;
	if(Node == NULL) return e;
	if(data <= Node->data) Node->left = Insert(Node->left, data);
	else if(data > Node->data) Node->right = Insert(Node->right, data);
	return Node;
}


// Iterative approach.
int getBSTHeight(BSTNode* Node) {
	int h1 = 0, h2 = 0;
	Node->data = 23;
	BSTNode* troot = Node;
	while(troot->left != NULL) {
		++h1;
		troot = troot->left;
	}
	while(Node->right != NULL) {
		++h2;
		Node = Node->right;
	}
	int height = max(h1, h2) + 1; // max(Height of left subtree, Height of right subtree) + 1 and +1 for edge connecting to root.
	return height;
}

// Recursive approach.
int height(BSTNode* Node) {
	if(Node == NULL) return -1;
	int lst = height(Node->left);
	int rst = height(Node->right);
	return max(lst, rst) + 1;
}

int main() {
	BSTNode* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	
	cout << height(root) << '\n';
}
