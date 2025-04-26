#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *right;
    BstNode *left;
};

BstNode *Insert(BstNode *Root, int value)
{
    if (Root == NULL)
    {
        BstNode *newNode = new BstNode();
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value <= Root->data)
    {
        Root->left = Insert(Root->left, value);
    }
    else
    {
        Root->right = Insert(Root->right, value);
    }
    return Root;
}

void print_InOrder(BstNode *Root)
{
    if (Root != NULL)
    {
        print_InOrder(Root->left);
        cout << Root->data << " ";
        print_InOrder(Root->right);
    }
}

void findPreSuc(BstNode *root, BstNode *&pre, BstNode *&suc, int data)
{
    if (root == NULL)
        return;

    if (root->data == data)
    {
        if (root->left != NULL)
        {
            BstNode *temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;
            pre = temp;
        }

        if (root->right != NULL)
        {
            BstNode *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            suc = temp;
        }
    }
    else if (data < root->data)
    {
        suc = root; 
        findPreSuc(root->left, pre, suc, data);
    }
    else
    {
        pre = root; 
        findPreSuc(root->right, pre, suc, data);
    }
}

int main()
{
    cout << "How many values you want to enter: ";
    int val;
    cin >> val;
    BstNode *Root = NULL;

    for (int i = 0; i < val; i++)
    {
        int value;
        cout << "Enter value to insert: ";
        cin >> value;
        Root = Insert(Root, value);
    }

    cout << "InOrder Traversal: ";
    print_InOrder(Root);
    cout << endl;

    int target;
    cout << "Enter value to find predecessor and successor: ";
    cin >> target;

    BstNode *pre = NULL, *suc = NULL;

    findPreSuc(Root, pre, suc, target);

    if (pre != NULL)
    {
        cout << "Predecessor is " << pre->data << endl;
    }
    else
    {
        cout << "Predecessor is NULL" << endl;
    }

    if (suc != NULL)
    {
        cout << "Successor is " << suc->data << endl;
    }
    else
    {
        cout << "Successor is NULL" << endl;
    }

}