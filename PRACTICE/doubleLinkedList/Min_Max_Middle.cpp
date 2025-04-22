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

int TotalNode(){
    Node* current = list;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
Node* min(Node* head) {
    Node* current = head;
    Node* minNode = head;
    while (current != NULL) {
        if (current->data < minNode->data) {
            minNode = current;
        }
        current = current->next;
    }
    Node*temp = minNode;
    minNode = list;
    list = temp;

    
    
}
    
Node* max(Node* head) {
    Node* current = head;
    Node* maxNode = head;
    while (current != NULL) {
        if (current->data > maxNode->data) {
            maxNode = current;
        }
        current = current->next;
    }
    return maxNode;
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
int MiddleNode(){
    int total  = TotalNode();
    int mid = total/2;
    Node* current = list;
    for(int i=0;i<mid;i++){
        current = current->next;
    }
    cout<< current->data;
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
            
        }
        cout << "Original List: ";
        print();
        cout << "\n";
        // cout << "Total Nodes: " << TotalNode() << endl;
        // cout << "Middle Node: "; 
        // MiddleNode();
        // cout << "\n";
        cout<<"MInimum Node in first place: "<<endl;
        min(list);
        print();


        
    }
}
