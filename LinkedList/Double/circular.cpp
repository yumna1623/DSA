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
    ptr->next = NULL;
    ptr->prev = NULL;

    cout << "Enter : ";
    cin >> ptr->data;
    if (list == NULL)
    {
        ptr->next = ptr;
        ptr->prev = ptr;
        list = ptr;
    }
    else
    {
        Node *current = list;
        while (current->next != list)
        {
            current = current->next;
        }
        current->next = ptr; // Link last node to new node
        ptr->prev = current; // New node's prev points to last node
        ptr->next = list;    // Circular link back to first node
        list->prev = ptr;    // First node's prev points to new last node
    }
}
void print()
{
    if (list == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *current = list;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != list);

    cout << "\n";
}
void Delete()
{
    Node *current = list;
    Node *prev = NULL;
    int toDelete;
    cout << "Enter the value you want to delete: ";
    cin >> toDelete;
    if (list->data == toDelete)
    {

        Node *temp = list;
        if (list->next == list)
        {
            list = NULL;
        }
        
        else
        {
            Node*last=list;
            while(last->next!=list){
                last=last->next;
            }
            list = list->next;
            // list->prev = last;
            last->next=list;
        }
        free(temp);
    }
    else{
        prev=list;
            current=list->next;
        while (current != list){
            if (current->data == toDelete){
                prev->next=current->next;
                free(current);
                return;
            }
            prev=current;
            current=current->next;
        }
    }
}

int Search()
{
    int toSearch;
    cout << "Enter value ";
    cin >> toSearch;

    Node *current = list;
    do
    {
        if (current->data == toSearch)
        {
            cout << "value found";
            return current->data;
        }
        else
        {
            current = current->next;
        }
    } while (current != list);
    cout << "value not found";
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
        Delete();
        print();
    }
}
