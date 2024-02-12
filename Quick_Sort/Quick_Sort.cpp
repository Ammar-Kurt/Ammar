#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
    int ind;

    node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
        ind = 0;
    }
};

class list
{
public:
    node* head = nullptr;
    node* tail = nullptr;
    int count = 0;

    list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add_at_tail(int x)
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
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            tail->ind = count;
            count++;
        }
    }

    void display()
    {
        for (node* current = head; current != nullptr; current = current->next)
        {
            cout << "===[ " << current->data << " ]===";
        }
    }

    node* partition(node* low, node* high)
    {
        node* pi = high;
        node* i = low->prev;

        for (node* j = low; j != high; j = j->next)
        {
            if (j->data <= pi->data)
            {
                if (i == nullptr) {
                    i = low;
                }
                else {
                    i = i->next;
                }
                swap(i->data, j->data);
            }
        }

        if (i == nullptr) {
            i = low;
        }
        else {
            i = i->next;
        }
        swap(i->data, pi->data);
        return i;
    }

    void quickSort(node* low, node* high)
    {
        if (low != nullptr && high != nullptr && low != high && low->prev != high)
        {
            node* pivot = partition(low, high);
            quickSort(low, pivot->prev);
            quickSort(pivot->next, high);
        }
    }
};

int main()
{
    list a1;
    a1.add_at_tail(12);
    a1.add_at_tail(45);
    a1.add_at_tail(23);
    a1.add_at_tail(6);
    a1.add_at_tail(56);
    a1.add_at_tail(8);
    cout << "Original List:" << endl;
    a1.display();
    cout << endl;

    if (a1.head != nullptr && a1.tail != nullptr)
    {
        a1.quickSort(a1.head, a1.tail);
        cout << "Sorted List:" << endl;
        a1.display();
    }
    else
    {
        cout << "Empty list." << endl;
    }

    return 0;
}
