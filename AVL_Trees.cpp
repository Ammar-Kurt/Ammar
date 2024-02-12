#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	int height;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
		height = 0;
	}
};

int hgt(Node* node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

int get_balance(Node* node) {
	if (node == NULL) {
		return 0;
	}
	int left_height = (node->left != NULL) ? node->left->height : 0;
	int right_height = (node->right != NULL) ? node->right->height : 0;
	return left_height - right_height;
}


Node* right_rotate(Node* x) {
	if (x == NULL || x->left == NULL) {
		return x;
	}

	Node* y = x->left;
	Node* t1 = y->right;

	y->right = x;
	x->left = t1;

	x->height = max(hgt(x->left), hgt(x->right)) + 1;
	y->height = max(hgt(y->left), hgt(y->right)) + 1;

	return y;
}

Node* left_rotate(Node* y) {
	if (y == NULL || y->right == NULL) {
		return y;
	}

	Node* x = y->right;
	Node* t1 = x->left;

	x->left = y;
	y->right = t1;

	y->height = max(hgt(y->left), hgt(y->right)) + 1;
	x->height = max(hgt(x->left), hgt(x->right)) + 1;

	return x;
}



Node* insertAVL(Node* root, int val)
{
	if (root == NULL)
	{
		return new Node(val);
	}

	else if (val > root->data)
	{
		root->right = insertAVL(root->right, val);
	}
	else if (val < root->data)
	{
		root->left = insertAVL(root->left, val);
	}
	else
		return root;

	root->height = 1 + max(hgt(root->left), hgt(root->right));

	int balance = get_balance(root);

	if (balance > 1 && val < root->left->data)
	{
		return right_rotate(root);
	}
	if (balance < -1 && val > root->right->data)
	{
		return left_rotate(root);
	}
	if (balance > 1 && val > root->left->data)
	{
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}
	if (balance < -1 && val < root->right->data)
	{
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}


void inorder(Node* root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << "  ";
	inorder(root->right);
}


int main()
{
		Node* root = NULL;
		root = insertAVL(root, 5);
		root = insertAVL(root, 1);
		root = insertAVL(root, 15);
		root = insertAVL(root, 10);
		root = insertAVL(root, 50);

		inorder(root);

		return 0; // Add this line to indicate a successful execution.
	

}