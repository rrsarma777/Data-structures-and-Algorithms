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

int findMin(BSTNode* Node) {
	if(Node == NULL) {
		cout << "Tree is Empty!" << '\n';
		return -1;
	}
	while(Node->left != NULL) Node = Node->left;
	return Node->data;
}

int findMax(BSTNode* Node) {
	if(Node == NULL) {
		cout << "Tree is Empty!" << '\n';
		return -1;
	}
	while(Node->right != NULL) Node = Node->right;
	return Node->data;
}

// Recursive approach.

int findMin1(BSTNode* Node) {
	if(Node == NULL) {
		cout << "Tree is Empty!" << '\n';
		return -1;
	}
	if(Node->left == NULL) return Node->data;
	return findMin1(Node->left);
}

int findMax1(BSTNode* Node) {
	if(Node == NULL) {
		cout << "Tree is Empty!" << '\n';
		return -1;
	}
	if(Node->right == NULL) return Node->data;
	return findMax1(Node->right);
}

int main() {
	BSTNode* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	
	cout << "Using Iterative approach."<< '\n';
	cout << "MIN : " << findMin(root) << '\n';
	cout << "MAX : " << findMax(root) << '\n';
	
	cout << "Using Recursive approach." << '\n';
	cout << "MIN : " << findMin1(root) << '\n';
	cout << "MAX : " << findMax1(root) << '\n';
}
