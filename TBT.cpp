#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool isThreaded;
};

Node *createNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->isThreaded = false;
    return newNode;
}

Node *insert(Node *root, int data) {
    if (!root)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data) {
        if (root->isThreaded) {
            root->isThreaded = false;
            root->right = insert(nullptr, data);
        } else
            root->right = insert(root->right, data);
    }
    return root;
}

void createThreads(Node *root, Node *&prev) {
    if (!root)
        return;

    createThreads(root->left, prev);

    if (prev && !prev->right) {
        prev->right = root;
        prev->isThreaded = true;
    }
    prev = root;

    createThreads(root->right, prev);
}

void inorder(Node *root) {
    Node *current = root;
    while (current && current->left)
        current = current->left;

    while (current) {
        cout << current->data << " ";
        if (current->isThreaded)
            current = current->right;
        else {
            current = current->right;
            while (current && current->left)
                current = current->left;
        }
    }
    cout << endl;
}

void preorder(Node *root) {
    Node *current = root;
    while (current) {
        cout << current->data << " ";
        if (current->left)
            current = current->left;
        else {
            while (current && current->isThreaded)
                current = current->right;
            if (current)
                current = current->right;
        }
    }
    cout << endl;
}

int main() {
    Node *root = nullptr;
    Node *prev = nullptr;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Pre-order Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            createThreads(root, prev);
            break;

        case 2:
            cout << "In-order Traversal: ";
            inorder(root);
            break;

        case 3:
            cout << "Pre-order Traversal: ";
            preorder(root);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
