#include <iostream>
#include <list>

const int TABLE_SIZE = 10;

class HashTable {
private:
    std::list<int> table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                chain.erase(it);
                std::cout << "Key " << key << " removed from the table." << std::endl;
                return;
            }
        }

        std::cout << "Key " << key << " not found in the table." << std::endl;
    }

    bool search(int key) {
        int index = hash(key);
        const auto& chain = table[index];

        for (int k : chain) {
            if (k == key) {
                std::cout << "Key " << key << " found in the table." << std::endl;
                return true;
            }
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

/*
Choose an operation:
1. Insert
2. Delete
3. Search
4. Quit
1
Enter a key to insert: 453
Choose an operation:
1. Insert
2. Delete
3. Search
4. Quit
1
Enter a key to insert: 3950
Choose an operation:
1. Insert
2. Delete
3. Search
4. Quit
1
Enter a key to insert: 29404
Choose an operation:
1. Insert
2. Delete
3. Search
4. Quit
1
Enter a key to insert: 7568
Choose an operation:
1. Insert
2. Delete
3. Search
4. Quit
2
Enter a key to delete: 29404
Key 29404 removed from the table.
Choose an operation:
1. Insert
2. Delete
3. Search
4. Quit
3
Enter a key to search: 7568
Key 7568 found in the table.
Choose an operation:
1. Insert
2. Delete
3. Search
4. Quit
4
EXITED SUCCESSFULLY
*/