#include <iostream>
using namespace std;

struct BSTNode {
	int data;
	BSTNode* left = NULL;
	BSTNode* right = NULL;
};

BSTNode* getNewNode(int data) {
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	return newNode;
}

BSTNode* Insert(BSTNode* Node, int data) {
	if(Node == NULL) {
		BSTNode* troot = getNewNode(data);
		return troot;
	}
	else if(data <= Node->data) {
		Node->left = Insert(Node->left, data);
	}
	else if(data > Node->data){
		Node->right = Insert(Node->right, data);
	}
	return Node;
}

bool search(BSTNode* Node, int ele) {
	if(Node == NULL) return false;
	if(Node->data == ele) return true;
	else if(ele <= Node->data) {
		search(Node->left, ele);
	}
	else if(ele > Node->data) {
		search(Node->right, ele);
	}
}

int main() {
	BSTNode* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	
	int ele = 12;
	
	if(search(root, ele)){
		cout << "Found " << ele << '\n';
	}
	else cout << "Element " << ele << " not found!" << '\n';
}
