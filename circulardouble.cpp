#include <iostream>
using namespace std;

struct node
{
	int data;
	node *prev;
	node *next;

	node()
	{
		next = nullptr;
		prev = nullptr;
		data = 0;
	}
};

class list
{
	node* head = new node;
	node* tail = new node;
public:
	list()
	{
		head = nullptr;
		tail = nullptr;
	}
	
	void display()
	{
		cout << endl << endl;
		node *current = head;
		do
		{
			cout << "---[ " << current->data << " ]---";
			current = current->next;

		} while (current->next!=head);
		cout << "---[ " << tail->data << " ]---";
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
			tail->next = head;
			head->prev = tail;
		}
	}

	void add_at_tail(int x)
	{
		node* temp = new node;
		temp->data = x;

		if (tail == nullptr)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			tail->next = head;
			head->prev = tail;
		}
	}
};

int main()
{
	list a1;
	a1.add_at_head(10);
	a1.add_at_head(15);
	a1.add_at_head(20);
	a1.add_at_head(25);
	a1.add_at_head(30);

	a1.display();


	a1.add_at_tail(50);
	a1.add_at_tail(60);

	a1.display();
}