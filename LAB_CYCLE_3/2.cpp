#include <iostream>
using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node()
    {
        data = 0;

        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int data);
    void print();
    void alternate_split();
};

void LinkedList::insert(int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::print()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "Empty List"
             << "\n";
    }

    cout << "{ ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << " }";
}

void LinkedList::alternate_split()
{
    LinkedList *list1 = new LinkedList();
    LinkedList *list2 = new LinkedList();

    Node *curr = head;
    bool to_list1 = true;

    while (curr)
    {
        if (to_list1)
        {
            list1->insert(curr->data);
        }
        else
        {
            list2->insert(curr->data);
        }
        to_list1 = !to_list1;
        curr = curr->next;
    }

    cout << "\n";
    list1->print();
    cout << "\n";
    list2->print();
}

int main()
{
    LinkedList list;
    list.insert(6);
    list.insert(4);
    list.insert(10);
    list.insert(13);
    list.insert(1);
    list.insert(7);
    list.insert(88);
    list.insert(10);
    list.insert(5);

    cout << "ORIGINAL LIST IS : ";
    list.print();

    cout << "\n\n";

    cout << "NEWLY CREATED SUBLISTS ARE : ";
    list.alternate_split();

    return 0;
}

/*

ORIGINAL LIST IS : { 6 4 10 13 1 7 88 10 5  }

NEWLY CREATED SUBLISTS ARE :
{ 6 10 1 88 5  }
{ 4 13 7 10  }

*/
