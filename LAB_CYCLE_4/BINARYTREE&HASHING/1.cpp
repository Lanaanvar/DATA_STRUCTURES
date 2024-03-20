#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    TreeNode* search(TreeNode* node, int key) {
        if (node == nullptr || node->data == key) {
            return node;
        }

        if (key < node->data) {
            return search(node->left, key);
        }

        return search(node->right, key);
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) { 
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }

    void insert(int value) {
        root = insert(root, value);
    }

    TreeNode* search(int key) {
        return search(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void inorder() {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void preorder() {
        std::cout << "Preorder Traversal: ";
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorder() {
        std::cout << "Postorder Traversal: ";
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    while (true) {
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Insert" << std::endl;
        std::cout << "2. Search" << std::endl;
        std::cout << "3. Delete" << std::endl;
        std::cout << "4. Inorder Traversal" << std::endl;
        std::cout << "5. Preorder Traversal" << std::endl;
        std::cout << "6. Postorder Traversal" << std::endl;
        std::cout << "7. Quit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                int insertValue;
                std::cout << "Enter a value to insert: ";
                std::cin >> insertValue;
                bst.insert(insertValue);
                break;
            case 2:
                int searchKey;
                std::cout << "Enter a key to search: ";
                std::cin >> searchKey;
                if (bst.search(searchKey)) {
                    std::cout << "Key " << searchKey << " found in the BST." << std::endl;
                } else {
                    std::cout << "Key " << searchKey << " not found in the BST." << std::endl;
                }
                break;
            case 3:
                int deleteKey;
                std::cout << "Enter a key to delete: ";
                std::cin >> deleteKey;
                bst.deleteNode(deleteKey);
                break;
            case 4:
                bst.inorder();
                break;
            case 5:
                bst.preorder();
                break;
            case 6:
                bst.postorder();
                break;
            case 7:
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
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
1
Enter a value to insert: 456
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
1
Enter a value to insert: 387
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
1
Enter a value to insert: 4564
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
1
Enter a value to insert: 39488
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
1
Enter a value to insert: 38490
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
1
Enter a value to insert: 36478
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
1
Enter a value to insert: 38849
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
2
Enter a key to search: 36478
Key 36478 found in the BST.
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
3
Enter a key to delete: 36748
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
4
Inorder Traversal: 387 456 4564 36478 38490 38849 39488
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
5
Preorder Traversal: 456 387 4564 39488 38490 36478 38849
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
6
Postorder Traversal: 387 36478 38849 38490 39488 4564 456
Choose an operation:
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Quit
7
EXITED SUCCESSFULLY
*/