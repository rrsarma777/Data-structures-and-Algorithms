#include <iostream>
#include <queue>
using namespace std;

struct BST {
	char data;
	BST* left = NULL;
	BST* right = NULL;
};

BST* insert(BST* root, char data) {
	BST* newNode = new BST();
	newNode->data = data;
	if(root == NULL) return newNode;
	if(data <= root->data) root->left = insert(root->left, data);
	else if(data > root->data) root->right = insert(root->right, data);
	return root;
}

void levelOrderTraversal(BST* root) {
	if(root == NULL) return;
	queue<BST*> q;
	q.push(root);
	while(!q.empty()) {
		BST* currNode = q.front();
		if(currNode->left != NULL) q.push(currNode->left);
		if(currNode->right != NULL) q.push(currNode->right);
		cout << currNode->data << '\n';
		q.pop();
	}
}

int main() {
	BST* root = NULL;
	root = insert(root, 'F');
	root = insert(root, 'D');
	root = insert(root, 'J');
	root = insert(root, 'B');
	root = insert(root, 'E');
	root = insert(root, 'G');
	root = insert(root, 'K');
	root = insert(root, 'A');
	root = insert(root, 'C');
	root = insert(root, 'I');
	root = insert(root, 'H');
	
	levelOrderTraversal(root);
}
