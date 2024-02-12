#include <iostream>
using namespace std;

struct product
{
	string name;
	int price;

	product(string name = "NONE", int price = 00)
	{
		this->name = name;
		this->price = price;
	}
};

class node
{
public:
	node* left;
	node* right;
	product* data;
	int height;

	node(product* p = nullptr)
	{
		left = nullptr;
		right = nullptr;
		data = p;
		height = 0;
	}
};



class AVL
{
	node* root;

public:
	AVL()
	{
		root = nullptr;
	}

	int get_bal(node* root)
	{
		return ((root->left->height) - (root->right->height));
	}

	int get_height(node* root)
	{
		return 1 + max((root->left->height), (root->right->height));
	}

	node* right_rotate(node* x)
	{
		node* y = nullptr;
		node* T1 = nullptr;

		x->left = y;
		y->right = T1;

		y->right = x;
		x->left = T1;

		y->height = get_height(y);
		x->height = get_height(x);

		return x;

	}

	node* left_rotate(node* x)
	{
		node* y = nullptr;
		node* T1 = nullptr;

		x->right = y;
		y->left = T1;

		y->left = x;
		x->right = T1;

		y->height = get_height(y);
		x->height = get_height(x);

		return x;

	}

	node* insert(node* root, string name, int price)
	{
		product* p = new product(name, price);
		if (root == NULL)
		{
			return new node(p);
		}

		else
		{
			if (price > root->data->price)
			{
				root->right = insert(root->right, name, price);
			}

			else if (price < root->data->price)
			{
				root->left = insert(root->left, name, price);
			}

			return root;
		}

		root->height = get_height(root);

		int bal = get_bal(root);

		if (bal > 1 && price < root->data->price)
		{
			left_rotate(root);

		}
		if (bal < -1 && price > root->data->price)
		{
			right_rotate(root);
		}
		if (bal > 1 && price > root->data->price)
		{
			root->left = right_rotate(root->left);
			left_rotate(root);
		}
		if (bal < -1 && price < root->data->price)
		{
			root->right = left_rotate(root->right);
			right_rotate(root);
		}

		return root;

	}

	node* get_min(node* root)
	{
		while (root->left != nullptr)
		{
			root = root->left;
		}
		return root;
	}

	node* Delete(node* root, string name, int price)
	{
		if (root == nullptr)
		{
			return root;
		}

		if (price < root->data->price)
		{
			root->left = Delete(root->left, name, price);
		}
		else if (price > root->data->price)
		{
			root->right = Delete(root->right, name, price);
		}
		else
		{
			if (root->left == nullptr)
			{
				node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				node* temp = root->left;
				delete root;
				return temp;
			}

			node* temp = get_min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data->name, temp->data->price);
		}

		root->height = get_height(root);

		int bal = get_bal(root);

		if (bal > 1 && price < root->data->price)
		{
			return left_rotate(root);
		}
		if (bal < -1 && price > root->data->price)
		{
			return right_rotate(root);
		}
		if (bal > 1 && price > root->data->price)
		{
			root->left = right_rotate(root->left);
			return left_rotate(root);
		}
		if (bal < -1 && price < root->data->price)
		{
			root->right = left_rotate(root->right);
			return right_rotate(root);
		}

		return root;
	}


	void in_order(node* root)
	{
		if (root == NULL)
		{
			return;
		}

		in_order(root->left);
		cout << "Name== " << root->data->name << endl;
		cout << "Price== " << root->data->price << endl;
		in_order(root->right);
	}

	bool is_balanced()
	{
		return is_balanced(root);
	}

	// Utility function to check if the tree is balanced
	bool is_balanced(node* root)
	{
		if (root == nullptr)
			return true;

		int balance_factor = get_bal(root);
		if (balance_factor > 1 || balance_factor < -1)
			return false;

		return is_balanced(root->left) && is_balanced(root->right);
	}
};


int main()
{
	AVL* tree=nullptr;
	node* root = nullptr;

	root = tree->insert(root, "surf", 10000);
	tree->insert(root, "ammar", 5000);
	tree->insert(root, "amm", 500);
	tree->insert(root, "ar", 20000);

	tree->in_order(root);

	cout << endl;

	tree->Delete(root, "ammar", 5000);

	tree->in_order(root);

	

}