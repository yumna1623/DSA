#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *list = NULL;
int current;

void insert()
{
    Node *ptr = (Node *)(malloc(sizeof(Node)));
    cout << "Enter";
    cin >> ptr->data;
    ptr->next = nullptr;
    if (list == NULL)
    {
        list = ptr;
    }
    else
    {
        Node *current = list;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = ptr;
    }
}

void print()
{
    Node *current = list;
    while (current != NULL)
    {
        cout << current->data;
        cout << "\n";
        current = current->next;
        cout << " ";
    }
}
void Delete(){

    int toDelete;
    cout<<"Enter value to Delete ";
    cin>>toDelete;

    Node*current= list;
    if (list->data == toDelete){
        Node*temp=list;
        Node*current=list;
        list = list->next;
        free(temp);
    }
    else{
        Node*prev = list;
        current=list->next;
        while(current!=NULL){
            if(current->data==toDelete){
                prev->next=current->next;
                free(current);
                break;
            }
            else{
                current=current->next;
                prev=prev->next;
            }
        }
    }
    }
int Search(){

    int toSearch;
    cout<<"Enter value to search ";
    cin>>toSearch;

    Node*current= list;
    while(current!=NULL){
        if(current->data == toSearch){
            cout<<"value found";
            return current->data;
        }
        else{
            current=current->next;
        }
    }
     cout<<"value not found";
}
int main()
{
    int num;
    cout << "Enter 1 to insert a value";
    cout << "Enter 2 to Search a value";
    cout << "Enter 2 to Delete a value";
    cin >> num;
    if (num == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            insert();
            print();
        }
        Delete();
        print();
        Search();
    }
}



















