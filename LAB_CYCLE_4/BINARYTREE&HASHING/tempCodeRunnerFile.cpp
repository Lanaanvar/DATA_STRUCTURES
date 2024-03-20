#include <iostream>

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    int double_hash(int key) {
        // Use a prime number less than TABLE_SIZE for the second hash function
        const int PRIME = 7;
        return PRIME - (key % PRIME);
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = -1;  
        }
    }

    void insert(int key) {
        int index = hash(key);
        int step = double_hash(key);

        while (table[index] != -1) {
            index = (index + step) % TABLE_SIZE;
        }

        table[index] = key;
    }

    void remove(int key) {
        int index = hash(key);
        int step = double_hash(key);

        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                std::cout << "Key " << key << " removed from the table." << std::endl;
                return;
            }
            index = (index + step) % TABLE_SIZE;
        }

        std::cout << "Key " << key << " not found in the table." << std::endl;
    }

    bool search(int key) {
        int index = hash(key);
        int step = double_hash(key);

        while (table[index] != -1) {
            if (table[index] == key) {
                std::cout << "Key " << key << " found in the table." << std::endl;
                return true;
            }
            index = (index + step) % TABLE_SIZE;
        }

        std::cout << "Key " << key << " not found in the table." << std::endl;
        return false;
    }
};

int main() {
    HashTable hashTable;

    while (true) {
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Insert" << std::endl;
        std::cout << "2. Delete" << std::endl;
        std::cout << "3. Search" << std::endl;
        std::cout << "4. Quit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                int key;
                std::cout << "Enter a key to insert: ";
                std::cin >> key;
                hashTable.insert(key);
                break;
            case 2:
                std::cout << "Enter a key to delete: ";
                std::cin >> key;
                hashTable.remove(key);
                break;
            case 3:
                std::cout << "Enter a key to search: ";
                std::cin >> key;
                hashTable.search(key);
                break;
            case 4:
                std::cout<<"EXITED SUCCESSFULLY";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}