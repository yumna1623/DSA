#include <iostream>
#include <malloc.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
int current;
vector<int> arr;

void insert(int data)
{
    Node *ptr = (Node *)(malloc(sizeof(Node)));
    ptr->data = data;
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
Node*Reverse_Between_Nodes(Node* head, int left, int right) {
    if (head == NULL || left >= right) return head;

    Node*current = head;
    while(current!=NULL){
        arr.push_back(current->data);
        current=current->next;
    
        int l = left - 1;
        int r = right - 1;
        while (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }


}
}

void print()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data;
        cout << "\n";
        current = current->next;
        cout << " ";
    }
}


int main()
{
    
    
        
            insert(100);
            insert(200);
            insert(300);
            insert(400);
            insert(500);
            print();
        
        Reverse_Between_Nodes(head, 1, 3);
    
    
}