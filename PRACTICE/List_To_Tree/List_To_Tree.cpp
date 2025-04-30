#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *left = NULL;
    Node *right = NULL;
};
int arr[5];

int size=0;

Node *head = NULL;
int current;

void insert(int data)
{
    Node *ptr = (Node *)(malloc(sizeof(Node)));
     ptr->data = data;
    arr[size] = data;
    size++;
    ptr->next = nullptr;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = ptr;
    }
}

void print(int arr[])
{
    cout << "The elements of the linked list are:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


Node*BuidBtree(int arr[] , int start , int end){
    
    int mid = (start + end) / 2;
    Node *Root = new Node;
    Root->data = arr[mid];
    Root->left = NULL;
    Root->right = NULL;
    if (start == end)
    {
        return Root;
    }
    if (start < mid)
    {
        Root->left = BuidBtree(arr, start, mid - 1);
    }
    if (mid < end)
    {
        Root->right = BuidBtree(arr, mid + 1, end);
    }
    return Root;

}
void print_InOrder(Node *Root) {
    if (Root != NULL) {
        print_InOrder(Root->left);
        cout << Root->data << " ";
        print_InOrder(Root->right);
    }
}
int main()
{    
            insert(0);
            insert(1);
            insert(2);
            insert(3);
            insert(4);
            print(arr);
            int start = 0;
            int end = size - 1;
            Node *head =  BuidBtree(arr , start , end);
            cout << "The elements of the binary tree are:\n";  
            print_InOrder(head); 

}