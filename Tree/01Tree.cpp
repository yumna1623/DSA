#include <iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode *Rchild;
    BstNode *Lchild;
};



// Function to insert a value into BST
BstNode *Insert(BstNode *Root, int value) {
    if (Root == NULL) {
        BstNode *newNode = new BstNode();
        newNode->data = value;
        newNode->Lchild = NULL;
        newNode->Rchild = NULL;
        return newNode;
    }
    if (value <= Root->data) {
        Root->Lchild = Insert(Root->Lchild, value);
    } else {
        Root->Rchild = Insert(Root->Rchild, value);
    }
    return Root;
}

bool Search(BstNode *Root, int ToSearch) {
    if (Root == NULL) {
        cout << "Tree is empty or value not found.\n";
        return false;
    } 
    else if (Root->data == ToSearch) {
        cout << "Value found: " << Root->data << endl;
        return true;
    } 
    else if (Root->data < ToSearch) {
        return Search(Root->Rchild, ToSearch);
    } 
    else {
        return Search(Root->Lchild, ToSearch);
    }
}

int findMax(BstNode*Root){
    
        while(Root->Rchild!=NULL){
            Root = Root->Rchild;
        }
        return Root->data;
}

int findMIn(BstNode*Root){

    while(Root->Lchild!=NULL){
        Root = Root->Lchild;
    }
    return Root->data;
}

BstNode* Delete(BstNode* Root, int ToDelete) {
    if (Root == NULL) {  // Base case: Tree is empty
        return Root;
    }

    if (Root->data == ToDelete) {
        // Case 1: No children (leaf node)
        if (Root->Lchild == NULL && Root->Rchild == NULL) {
            delete Root;
            return NULL;
        }
        // Case 2: One child (left child exists)
        else if (Root->Lchild != NULL && Root->Rchild == NULL) {
            BstNode* temp = Root->Lchild;
            delete Root;
            return temp;
        }
        // Case 3: One child (right child exists)
        else if (Root->Lchild == NULL && Root->Rchild != NULL) {
            BstNode* temp = Root->Rchild;
            delete Root;
            return temp;
        }
        // Case 4: Two children
        else {
            int maxValue = findMax(Root->Lchild); // Get the max from the left subtree
            Root->data = maxValue; // Replace the root value
            Root->Lchild = Delete(Root->Lchild, maxValue); // Delete the max node in left subtree
            return Root;
        }
    }
    // Recursive calls
    else if (ToDelete < Root->data) {
        Root->Lchild = Delete(Root->Lchild, ToDelete);
    } 
    else {
        Root->Rchild = Delete(Root->Rchild, ToDelete);
    }
    return Root;
}
// PreOrder traversal (Root, Left, Right)
void print_PreOrder(BstNode *Root) {
    if (Root != NULL) {
        cout << Root->data << " ";
        print_PreOrder(Root->Lchild);
        print_PreOrder(Root->Rchild);
    }
}

// PostOrder traversal (Left, Right, Root)
void print_PostOrder(BstNode *Root) {
    if (Root != NULL) {
        print_PostOrder(Root->Lchild);
        print_PostOrder(Root->Rchild);
        cout << Root->data << " ";
    }
}

// InOrder traversal (Left, Root, Right)
void print_InOrder(BstNode *Root) {
    if (Root != NULL) {
        print_InOrder(Root->Lchild);
        cout << Root->data << " ";
        print_InOrder(Root->Rchild);
    }
}

int main() {
    int value, choice,del;
    BstNode *Root = NULL;

    while (choice!=7) {
        cout << "\nMenu:\n1. Insert\n2. Search\n3. Print PreOrder\n4. Print InOrder\n5. Print PostOrder\n6. Delete\n7. EXIT\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                Root = Insert(Root, value);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                Search(Root, value);
                break;

            case 3:
                cout << "PreOrder Traversal: ";
                print_PreOrder(Root);
                cout << endl;
                break;

            case 4:
                cout << "InOrder Traversal: ";
                print_InOrder(Root);
                cout << endl;
                break;

            case 5:
                cout << "PostOrder Traversal: ";
                print_PostOrder(Root);
                cout << endl;
                break;

            case 6:
                // cout << "Enter value to delete: ";
                // int ToDelete;
                Root = Delete(Root,40);
                break;

                case 7:
                cout << "Exiting program.\n";
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
