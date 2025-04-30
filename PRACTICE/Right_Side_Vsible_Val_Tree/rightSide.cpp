#include <iostream>
#include <algorithm>

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





int treeLevel(BtNode* root) {
    if (root == nullptr)
        return 0;
    
    int leftLevel = treeLevel(root->left);
    int rightLevel = treeLevel(root->right);
    
    return 1 + max(leftLevel, rightLevel);
}

void RightSideVisible(BtNode* root, int level, int* maxLevel) {
    if (root == NULL) {
        return;
    }

    if (*maxLevel < level) {
        cout << root->data << " ";
        *maxLevel = level;
    }

    RightSideVisible(root->right, level + 1, maxLevel);
    RightSideVisible(root->left, level + 1, maxLevel);
}

void print_RightSideVisible(BtNode* root) {
    int maxLevel = 0;
    RightSideVisible(root, 1, &maxLevel);
}



void print_InOrder(BtNode* root) {
    if (root == NULL) return;
    print_InOrder(root->left);
    cout << root->data << " ";
    print_InOrder(root->right);
}



int main() {
    BtNode *root = NULL;
    root = Insert(root, 4);
    Insert(root, 5);
    Insert(root, 6);
    Insert(root, 7);
    // root = Insert(root, 1);
    // Insert(root, 2);
    // Insert(root, 3);
    // Insert(root, 4);
    
    cout << "InOrder Traversal: ";
    print_InOrder(root);
    cout << endl;

    cout << "Right Side View: ";
    print_RightSideVisible(root);
    cout << endl;

    return 0;
}
