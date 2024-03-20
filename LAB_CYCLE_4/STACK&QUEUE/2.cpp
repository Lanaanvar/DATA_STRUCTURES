#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    bool is_empty() {
        return size == 0;
    }

    int stack_size() {
        return size;
    }

    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        if (!is_empty()) {
            int poppedItem = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
            return poppedItem;
        } else {
            std::cout << "Stack is empty. Cannot pop an item." << std::endl;
            return -1; 
        }
    }
};

int main() {
    Stack stack;

    while (true) {
        cout << "Choose an operation:" << std::endl;
        cout << "1. Push" << std::endl;
        cout << "2. Pop" << std::endl;
        cout << "3. Check if stack is empty" << std::endl;
        cout << "4. Get stack size" << std::endl;
        cout << "5. Quit" << std::endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter a value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                if (!stack.is_empty()) {
                    cout << "Popped item: " << stack.pop() << std::endl;
                } else {
                    cout << "Stack is empty. Cannot pop an item." << std::endl;
                }
                break;
            case 3:
                cout << "Is stack empty? " << stack.is_empty() << std::endl;
                break;
            case 4:
                cout << "Stack size: " << stack.stack_size() << std::endl;
                break;
            case 5:
                cout<<"EXITED SUCCESSFULLY";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}

/*
Choose an operation:
1. Push
2. Pop
3. Check if stack is empty
4. Get stack size
5. Quit
1
Enter a value to push: 33
Choose an operation:
1. Push
2. Pop
3. Check if stack is empty
4. Get stack size
5. Quit
1
Enter a value to push: 44
Choose an operation:
1. Push
2. Pop
3. Check if stack is empty
4. Get stack size
5. Quit
1
Enter a value to push: 444
Choose an operation:
1. Push
2. Pop
3. Check if stack is empty
4. Get stack size
5. Quit
1
Enter a value to push: 6666
Choose an operation:
1. Push
2. Pop
3. Check if stack is empty
4. Get stack size
5. Quit
2
Popped item: 6666
Choose an operation:
1. Push
2. Pop
3. Check if stack is empty
4. Get stack size
5. Quit
3
Is stack empty? 0
Choose an operation:
1. Push
2. Pop
3. Check if stack is empty
4. Get stack size
5. Quit
4
Stack size: 3
Choose an operation:
1. Push
2. Pop
3. Check if stack is empty
4. Get stack size
5. Quit
5
EXITED SUCCESSFULLY
*/