// 2 binary tree check if equal have same structure
//  and sort nodes in dec order
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

//ascending order
void print_InOrder(BtNode* root) {
    if (root == NULL) {
        return;
    }
    print_InOrder(root->left);
    cout << root->data << " ";
    print_InOrder(root->right);
}

void Reverse_InOrder(BtNode* root) {
    if (root == NULL) {
        return;
    }
    Reverse_InOrder(root->right);
    cout << root->data << " ";
    Reverse_InOrder(root->left);
}

bool isIdentical(BtNode* root1, BtNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if(root1->data != root2->data) {
        return false;
    }

    return  isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

int main() {
    BtNode *root1 = NULL;
    root1 = Insert(root1, 10);
    Insert(root1, 20);
    Insert(root1, 30);
    Insert(root1, 5);
    Insert(root1, 15);
    Insert(root1, 25);

    cout << "1st Tree InOrder Traversal: ";
    print_InOrder(root1);
    cout << endl;


    BtNode *root2 = NULL;
    root2 = Insert(root2, 10);
    Insert(root2, 20);
    Insert(root2, 30);
    Insert(root2, 5);
    Insert(root2, 15);
    Insert(root2, 25);

    cout << "2nd Tree InOrder Traversal: ";
    print_InOrder(root2);
    cout << endl;

    // cout << "1st Tree Reverse InOrder Traversal: ";
    // Reverse_InOrder(root1);
    // cout << endl;
    // cout << endl;

    // cout << "2nd Tree Reverse InOrder Traversal: ";
    // Reverse_InOrder(root2);
    // cout << endl;
    // cout << endl;


    // isIdentical(root1, root2) ;
    if(isIdentical(root1, root2)) {
        cout << "Both trees are identical." << endl;
    } else {
        cout << "Trees are not identical." << endl;
    }
}
