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
void Delete(){
    Node *current = list;
    Node*prev=NULL;
    int toDelete;
    cout<<"Enter value to delete"<<endl;
    cin>>toDelete;
        if(list->data==toDelete){
            Node*prev=NULL;
            Node*temp=list;
            if(list->next==NULL){
                list=NULL;
            }
            else{
                list=list->next;
                list->prev=NULL;
                
            }
        free(temp);
        }
        else{
            prev=list;
            current=list->next;
            while(current!=NULL){
                if(current->data==toDelete){
                    prev->next = current->next;
                free(current);
                cout << "Deleted " << toDelete << " from the list." << endl;
                return;
                }
                prev = current;
                current = current->next;
            }
        }
}
void print()
{
    Node *current = list;
    do{
        cout << current->data;
        cout << "\n";
        current = current->next;
        cout << " ";
    }
    while (current != NULL);
    
}

int Search(){
    int toSearch;
    cout<<"Enter value ";
    cin>>toSearch;

    Node*current= list;
    do{
        if(current->data == toSearch){
            cout<<"value found";
            return current->data;
        }
        else{
            current=current->next;
        }
    }
    while(current!=NULL);
     cout<<"value not found";
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
