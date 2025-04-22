#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Utility to get height of the node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Utility to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create new node
Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Right Rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Insert a node
Node* insert(Node* node, int key) {
    if(node == NULL){
        return createNode(key);
    }

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Balancing
    if (balance > 1 && key < node->left->data) return rightRotate(node);        // Left Left
    if (balance < -1 && key > node->right->data) return leftRotate(node);       // Right Right
    if (balance > 1 && key > node->left->data) {                                 // Left Right
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {                               // Right Left
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    int n, value;
    cout << "Enter number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal of AVL Tree: ";
    inorder(root);
    cout << endl;

}
