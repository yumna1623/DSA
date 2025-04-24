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
Node* moveMinToFront(Node* head) {
    if (!head || !head->next) return head;

    Node* minNode = head;
    Node* current = head;

    while (current) {
        if (current->data < minNode->data) {
            minNode = current;
        }
        current = current->next;
    }

    if (minNode == head) return head;

    if (minNode->prev) minNode->prev->next = minNode->next;
    if (minNode->next) minNode->next->prev = minNode->prev;

    minNode->prev = nullptr;
    minNode->next = head;
    head->prev = minNode;
    head = minNode;

    return head;
}
Node* moveMaxToEnd(Node* head) {
    if (head == NULL) return head;

    Node* maxNode = head;
    Node* current = head;

    while (current) {
        if (current->data > maxNode->data) {
            maxNode = current;
        }
        current = current->next;
    }

    if (maxNode->next == nullptr) return head;

    if (maxNode->prev) maxNode->prev->next = maxNode->next;
    else head = maxNode->next;
    if (maxNode->next) maxNode->next->prev = maxNode->prev;

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = maxNode;
    maxNode->prev = tail;
    maxNode->next = nullptr;

    return head;
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
        cout << " ";
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
        list = moveMinToFront(list);
        print();
        cout << "\n";
        cout<<"Maximum Node in last place: "<<endl;
        list = moveMaxToEnd(list);
        print();
        


        
    }
}
