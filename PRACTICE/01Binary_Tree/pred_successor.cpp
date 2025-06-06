#include <iostream>
using namespace std;

struct BtNode {
    float data;
    BtNode *left;
    BtNode *right;
};

BtNode* Insert(BtNode* root, float value) {
    if (root == NULL) {
        BtNode* newNode = new BtNode();
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (root->left == NULL) {
        root->left = Insert(root->left, value);
    }
    else if (root->right == NULL) {
        root->right = Insert(root->right, value);
    }
    else {
        root->left = Insert(root->left, value);
    }

    return root;
}

bool Search(BtNode* root, float toSearch) {
    if (root == NULL) {
        return false;
    }
    if (root->data == toSearch) {
        return true;
    }

    return Search(root->left, toSearch) || Search(root->right, toSearch);
}

void print_InOrder(BtNode* root) {
    if (root == NULL) {
        return;
    }
    print_InOrder(root->left);
    cout << root->data << " ";
    print_InOrder(root->right);
}

BtNode* predecessor = NULL;
BtNode* successor = NULL;
BtNode* prevNode = NULL;


void findPredecessorAndSuccessor(BtNode* root, int target) {
    if (root == NULL) {
        return;
    }

    findPredecessorAndSuccessor(root->left, target);

    if (root->data == target) {
        predecessor = prevNode;
    }
    if (prevNode != NULL && prevNode->data == target && successor == NULL) {
        successor = root;
    }

    prevNode = root;

    findPredecessorAndSuccessor(root->right, target);
}

void displayPredecessorAndSuccessor() {
    if (predecessor != NULL) {
        cout << "Predecessor: " << predecessor->data << endl;
    } else {
        cout << "No Predecessor.\n";
    }

    if (successor != NULL) {
        cout << "Successor: " << successor->data << endl;
    } else {
        cout << "No Successor.\n";
    }
}

int main() {
    BtNode *root = NULL;
    root = Insert(root, 10);
    Insert(root, 20);
    Insert(root, 30);
    Insert(root, 5);
    Insert(root, 15);
    Insert(root, 25);

    cout << "InOrder Traversal: ";
    print_InOrder(root);
    cout << endl;

    float target;
    cout << "Enter value to find predecessor and successor: ";
    cin >> target;

    findPredecessorAndSuccessor(root, target);
    displayPredecessorAndSuccessor();

}
