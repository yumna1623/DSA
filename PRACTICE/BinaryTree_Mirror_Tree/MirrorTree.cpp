#include <iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode *right;
    BstNode *left;
};



BstNode* Insert(BstNode* root, int value) {
    if (root == NULL) {
        BstNode* newNode = new BstNode();
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
BstNode*MirriorTree(BstNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // BstNode* temp = root->left;
    // root->left = root->right;
    // root->right = temp;
    swap(root->left, root->right);

    MirriorTree(root->left);
    MirriorTree(root->right);

    return root;
}



// InOrder traversal (Left, Root, Right)
void print_InOrder(BstNode *Root) {
    if (Root != NULL) {
        print_InOrder(Root->left);
        cout << Root->data << " ";
        print_InOrder(Root->right);
    }
}

int main() {
    
    
    BstNode *Root = NULL;
    cout<<"Enter the number of nodes: ";
    int n;
    cin>>n;
    cout<<"Enter the values of nodes: ";
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        Root = Insert(Root, value);

    }
    print_InOrder(Root);
    cout << endl;
    cout << "Mirror Tree: ";
    BstNode* mirrorRoot = MirriorTree(Root);
    print_InOrder(mirrorRoot);

    
}
