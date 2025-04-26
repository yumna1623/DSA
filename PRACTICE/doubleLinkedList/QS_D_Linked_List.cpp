// insert print 
// store address of last element
// in each node index need to be maintained that is count of node in list
// implement quick sort in that double LinkedList
#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *list = NULL;
int current;

void insert()
{
    Node *ptr = (Node *)(malloc(sizeof(Node)));
    cout << "Enter";
    cin >> ptr->data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (list == NULL)
    {
        list = ptr;
    }
    else
    {
        Node *current = list;
        while (current->next!= NULL)
        {
              current=current->next;
        }
        current->next = ptr;
        ptr->prev=current;
    }
}

void print() {
    Node *current = list;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void AddressOfLastNode(Node*list){

    Node*current = list;
    Node*temp=list;

    while(current->next!=NULL){
        current = current->next;
    }
    cout<<"Address of last node :";
    cout<<current;
    cout<<"Value in last node ";
    cout<<current->data;
}

Node*QuickSort(Node*list){

}

int main()
{
    int num;
    cout << "Enter 1 to insert a value";
    cin >> num;
    if (num == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            insert();
            print();
        }
        
    }
    AddressOfLastNode(list);
    cout<<"List after Quick Sort :";
    QuickSort(list);
}
