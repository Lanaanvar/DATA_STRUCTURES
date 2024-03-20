#include <iostream>

class CircularQueue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool is_empty() {
        return size == 0;
    }

    int queue_size() {
        return size;
    }

    void enqueue(int item) {
        if (size < MAX_SIZE) {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = item;
            size++;
        } else {
            std::cout << "Queue is full. Cannot enqueue item: " << item << std::endl;
        }
    }

    int dequeue() {
        if (!is_empty()) {
            int dequeuedItem = arr[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
            size--;
            return dequeuedItem;
        } else {
            std::cout << "Queue is empty. Cannot dequeue an item." << std::endl;
            return -1; 
        }
    }
};

int main() {
    CircularQueue queue;

    while (true) {
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Check if queue is empty" << std::endl;
        std::cout << "4. Get queue size" << std::endl;
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                int value;
                std::cout << "Enter a value to enqueue: ";
                std::cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                if (!queue.is_empty()) {
                    std::cout << "Dequeued item: " << queue.dequeue() << std::endl;
                } else {
                    std::cout << "Queue is empty. Cannot dequeue an item." << std::endl;
                }
                break;
            case 3:
                std::cout << "Is queue empty? " << queue.is_empty() << std::endl;
                break;
            case 4:
                std::cout << "Queue size: " << queue.queue_size() << std::endl;
                break;
            case 5:
                std::cout<<"EXITED SUCCESSFULLY";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}

/*
Choose an operation:
1. Enqueue
2. Dequeue
3. Check if queue is empty
4. Get queue size
5. Quit
1
Enter a value to enqueue: 3994
Choose an operation:
1. Enqueue
2. Dequeue
3. Check if queue is empty
4. Get queue size
5. Quit
1
Enter a value to enqueue: 3948
Choose an operation:
1. Enqueue
2. Dequeue
3. Check if queue is empty
4. Get queue size
5. Quit
2
Dequeued item: 2333
Choose an operation:
1. Enqueue
2. Dequeue
3. Check if queue is empty
4. Get queue size
5. Quit
3
Is queue empty? 0
Choose an operation:
1. Enqueue
2. Dequeue
3. Check if queue is empty
4. Get queue size
5. Quit
4
Queue size: 3
Choose an operation:
1. Enqueue
2. Dequeue
3. Check if queue is empty
4. Get queue size
5. Quit
5
EXITED SUCCESSFULLY
*/
