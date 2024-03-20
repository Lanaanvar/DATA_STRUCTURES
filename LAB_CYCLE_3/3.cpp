#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int data)
    {

        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void printForward()
    {
        Node *currNode = head;

        cout << "{ ";
        while (currNode)
        {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << " }";
        cout << endl;
    }

    void printBackward()
    {
        Node *currNode = tail;
        cout << "{ ";
        while (currNode)
        {
            cout << currNode->data << " ";
            currNode = currNode->prev;
        }
        cout << " }";
        cout << endl;
    }

    void convertToDoubly()
    {
        Node *currNode = head;
        Node *prev_node = nullptr;

        while (currNode)
        {
            currNode->prev = prev_node;
            prev_node = currNode;
            currNode = currNode->next;
        }

        tail = prev_node;
    }
};

int main()
{
    DoublyLinkedList doublyList;

    doublyList.insert(1);
    doublyList.insert(2);
    doublyList.insert(3);
    doublyList.insert(4);
    doublyList.insert(5);

    cout << "Original singly linked list:" << endl;
    doublyList.printForward();

    doublyList.convertToDoubly();

    cout << "Doubly linked list (forward traversal):" << endl;
    doublyList.printForward();

    cout << "Doubly linked list (backward traversal):" << endl;
    doublyList.printBackward();

    return 0;
}

/*
Original singly linked list:
{ 1 2 3 4 5  }
Doubly linked list (forward traversal):
{ 1 2 3 4 5  }
Doubly linked list (backward traversal):
{ 5 4 3 2 1  }
*/