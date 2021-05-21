#include <iostream>
using namespace std;

struct BSTNode {
	char data;
	BSTNode* left = NULL;
	BSTNode* right = NULL;
};

BSTNode* insert(BSTNode* root, char data) {
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	if(root == NULL) return newNode;
	if(data <= root->data) root->left = insert(root->left, data);
	else if(data > root->data) root->right = insert(root->right, data);
	return root;
}

// Space complexity(stack frames in stack) is O(h). i.e in worst case it is O(n) if all nodes are either left or right. avg/best case : O(logn).
void preorder(BSTNode* root) {
	if(root == NULL) return;
	cout << root->data << ' ';
	preorder(root->left);
	preorder(root->right);
}

void inorder(BSTNode* root) {
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}

void postorder(BSTNode* root) {
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << ' ';
}

int main() {
	BSTNode* root = NULL;
	root = insert(root, 'F');
	root = insert(root, 'D');
	root = insert(root, 'B');
	root = insert(root, 'E');
	root = insert(root, 'A');
	root = insert(root, 'C');
	root = insert(root, 'J');
	root = insert(root, 'G');
	root = insert(root, 'K');
	root = insert(root, 'I');

	cout << "Preorder : ";
	preorder(root);
	cout << '\n';

	cout << "Inorder : ";
	inorder(root);
	cout << '\n';

	cout << "Postorder : ";
	postorder(root);
	cout << '\n';
}

// For all traversals Time-complexiy will be O(n).
