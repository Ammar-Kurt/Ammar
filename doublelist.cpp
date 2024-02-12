#include <iostream>
using namespace std;

struct node
{
	int data;
	node *prev;
	node* next;

	node()
	{
		data = 0;
		prev = nullptr;
		next = nullptr;
	}
};

class List
{
	node* head = new node;
	node* tail = new node;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	void display()
	{
		cout << endl << endl;
		for (node* current = head; current != tail; current = current->next)
		{
			cout << "---[ " << current->data << " ]---";
		}
				cout<< "---[ " <<tail->data << " ]---";
		
	}
	void display_rev()
	{
		cout << endl << endl;
		for (node* current = tail; current != head; current = current->prev)
		{
			cout << "---[ " << current->data << " ]---";
		}
				cout << "---[ " << head->data << " ]---";
		
	}

	void displaytail()
	{
		if (tail != nullptr)
			cout << "Tail data: " << tail->data << endl;
		else
			cout << "Tail is nullptr, list is empty." << endl;
	}

	void add_at_head(int x)
	{
		node* temp = new node;
		temp->data = x;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void add_after(int x, int y)
	{
		node* temp = new node;
		temp->data = x;
		for (node* current = head; current != tail; current = current->next)
		{
			if (current->data == y)
			{
				current->next->prev = temp;
				temp->next = current->next;
				current->next = temp;
				temp->prev=current;

			}
		}
	}


};

int main()
{
	List a1;
	a1.add_at_head(10);
	a1.add_at_head(20);
	a1.add_at_head(40);
	a1.add_at_head(45);
	a1.add_at_head(50);
	a1.add_after(35, 40);
	a1.add_after(1947, 35);

	a1.display();

	a1.display_rev();

	a1.displaytail();
}