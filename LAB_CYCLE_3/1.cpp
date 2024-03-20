#include <iostream>
#include <cstdlib>
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

    void search(int key);
    void insert(int data);
    void print();
    void count_duplicates(int key);
    void remove_duplicates(int key);
    void insert_pos(int key, int pos);
};

void LinkedList::search(int key)
{
    Node *currNode = head;
    int currIndex = 1;

    while (currNode && currNode->data != key)
    {
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode && currNode->data == key)
    {
        cout<< currIndex<<"\n";
        currNode = currNode->next;
        currIndex++;
    }
    else{
        cout<<"NOT FOUND"<<"\n";
    }
}

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
    cout<<"\n";
    Node *temp = head;

    if (head == NULL)
    {
        cout << "Empty List"
             << "\n";
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<"\n\n";
}

void LinkedList::count_duplicates(int key)
{
    int freq[50] = {0};

    Node *currNode = head;
    int currIndex = 1;

    while (currNode)
    {
        freq[currNode->data]++;
        currNode = currNode->next;
        currIndex++;
    }

    if (freq[key] > 1)
    {
        cout << freq[key] << "\n";
    }
    else
    {
        cout << "NO DUPLICATES"
             << "\n";
    }
}

void LinkedList::remove_duplicates(int key)
{
    int freq[50] = {0};

    Node *currNode = head;
    while (currNode)
    {
        freq[currNode->data]++;
        currNode = currNode->next;
    }

    currNode = head;
    Node *prevNode = nullptr;

    while (currNode)
    {
        if (currNode->data == key && freq[key] > 1)
        {
            if (prevNode)
            {
                prevNode->next = currNode->next;
                Node *temp = currNode;
                currNode = currNode->next;
                delete temp;
            }
            else
            {
                head = currNode->next;
                delete currNode;
                currNode = head;
            }
            freq[key]--;
        }
        else
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
}

void LinkedList::insert_pos(int key, int pos)
{
    if (pos < 0)
    {
        cout<<"LIST TOO SMALL"<<"\n";
    }

    int currIndex = 0;
    Node *currNode = head;

    while (currNode && pos > currIndex)
    {
        currNode = currNode->next;
        currIndex++;
    }

    Node *newNode = new Node();
    newNode->data = key;

    if (pos >= 0 && currNode == NULL)
    {
        // If pos is greater than the current size of the list, insert at the end
        Node *lastNode = head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    else
    {
        // Insert the new node at the specified position
        newNode->next = currNode->next;
        currNode->next = newNode;
    }

}

int main()
{
    LinkedList list;

    int n;
    cout << "Enter number of terms : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number : ";
        int num;
        cin >> num;
        list.insert(num);
    }
    list.print();

    char x;
    // int a, b, f, d, pos, j; // Declare variables for user input
    int j;
    do
    {
        cout << "s. Search"
             << "\n";
        cout << "c. count duplicates"
             << "\n";
        cout << "r. remove duplicates"
             << "\n";
        cout << "i. insert"
             << "\n";
        cout << "e. exit"
             << "\n";

        cout << "Enter your choice: ";
        cin >> x;

        switch (x)
        {
        case 's':
            cout << "Enter number to search : ";
            int a;
            cin >> a;
            list.search(a);
            cout<<"\n\n";
            break;

        case 'c':
            cout << "Enter number to count duplicates : ";
            int b;
            cin >> b;
            list.count_duplicates(b);
            cout<<"\n\n";
            break;

        case 'r':
            cout << "Enter number to remove duplicates : ";
            int f;
            cin >> f;
            list.remove_duplicates(f);
            list.print();
            cout<<"\n\n";
            break;

        case 'i':
            cout << "Enter number and index to insert : ";
            int d, pos;
            cin >> d >> pos;
            list.insert_pos(d, pos);
            cout << "\n";
            list.print();
            cout<<"\n\n";
            break;

        case 'e':
            exit(0); // Properly exit the program
            break;

        default:
            cout << "Wrong entry..Retry";
            break;
        }

    } while (x != 'e');

    return 0;
}

/*
Enter number of terms : 6
Enter the number : 10
Enter the number : 1
Enter the number : 0
Enter the number : 14
Enter the number : 5
Enter the number : 45

10 1 0 14 5 45 

s. Search
c. count duplicates
r. remove duplicates
i. insert
e. exit

Enter your choice: s
Enter number to search : 11

NOT FOUND

s. Search
c. count duplicates
r. remove duplicates
i. insert
e. exit
Enter your choice: i
Enter number and index to insert : 5 7


10 1 0 14 5 45 5

s. Search
c. count duplicates
r. remove duplicates
i. insert
e. exit
Enter your choice: s
Enter number to search : 5

5 7

s. Search
c. count duplicates
r. remove duplicates
i. insert
e. exit
Enter your choice: i
Enter number and index to insert : 50 9


10 1 0 14 5 45 5 50

s. Search
c. count duplicates
r. remove duplicates
i. insert
e. exit
Enter your choice: i
Enter number and index to insert : 5 2


10 5 1 0 14 5 45 5

s. Search
c. count duplicates
r. remove duplicates
i. insert
e. exit
Enter your choice: c
Enter number to count duplicates : 5

2

s. Search
c. count duplicates
r. remove duplicates
i. insert
e. exit
Enter your choice: r
Enter number to remove duplicates : 5

10 5 1 0 14 45

s. Search
c. count duplicates
r. remove duplicates
i. insert
e. exit
Enter your choice: e

*/