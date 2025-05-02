#include <iostream>
using namespace std;

struct BtNode {
    int data;
    BtNode *left;
    BtNode *right;
};

BtNode* Insert(BtNode* root, int value) {
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

bool Search(BtNode* root, int toSearch) {
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

BtNode*MirriorTree(BtNode* root) {
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


int  BtreeHeight(BtNode* root) {
    if (root == NULL) {
        return 0;
    }
    return max(BtreeHeight(root->left), BtreeHeight(root->right)) + 1;
}

int Level(BtNode* root, int data, int level) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return level;
    }

    int downlevel = Level(root->left, data, level + 1);
    if (downlevel != 0) {
        return downlevel;
    }

    downlevel = Level(root->right, data, level + 1);
    return downlevel;
}

int main() {
    BtNode *root = NULL;
    

    root = Insert(root,1);
     Insert(root,2);
     Insert(root,3);


    cout << "InOrder Traversal: ";
    print_InOrder(root);
    cout << endl;

    int target;
    cout << "Enter value to find predecessor and successor: ";
    cin >> target;

    findPredecessorAndSuccessor(root, target);
    displayPredecessorAndSuccessor();

    cout<<"Height of the tree: " << BtreeHeight(root) << endl;

    cout << "Level of " << target << ": " << Level(root, target, 1) << endl;

    cout<<"Mirror Image of the tree is: ";
    MirriorTree(root);
    print_InOrder(root);




}
