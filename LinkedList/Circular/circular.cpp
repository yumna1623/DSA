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
    if (list == NULL)
    {
        ptr->next = list;
        list = ptr;
    }
    else
    {
        Node *current = list;
        while (current->next != list)
        {
            current = current->next;
        }
        current->next = ptr;
    }
    ptr->next = list;
}
void print()
{
    Node *current = list;
    do
    {
        cout << current->data;
        cout << "\n";
        current = current->next;
        cout << " ";
    } while (current != list);
}
void Delete() {
    
    int toDelete;
    cout << "Enter value to delete: ";
    cin >> toDelete;

    Node *current = list;
    Node *prev = NULL;

    if (list->data == toDelete) {
        Node *temp = list;

        if (list->next == list) {
            list = NULL;
        } else {
            Node *last = list;
            while (last->next != list) {
                last = last->next;
            }
            list = list->next;  
            last->next = list;   
        }

        free(temp);
        cout << toDelete << "Deleted";
        return;
    } else {  
        prev = list;
        current = list->next;

        while (current != list) {  
            if (current->data == toDelete) {
                prev->next = current->next;  
                Node*temp=current;
                current=current->next;
                free(temp);
           }
            prev=current;
            current=current->next;
            
        }

        cout << "Value not found in the list." << endl;
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
        }
        Delete();
        print();
    }
