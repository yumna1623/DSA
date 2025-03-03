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
void insert(){

    Node*ptr=(Node*)(malloc(sizeof(Node)));
    cout << "Enter";
    cin >> ptr->data;
    ptr->next = nullptr;
    if(list==NULL){
        list=ptr;
    }
    else{
        Node*current=list;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=ptr;
    }
}
void print(){
    Node*current=list;
    while(current!=NULL){
        cout<<current->data;
        cout<<"\n ";
        current=current->next;
    }
}
Node* swap(){
    
    cout<<"Enter which numbers you want to swap";
    int x,y;
    cin>>x;
    cin>>y;
    if(x==y)return list;

    Node *prevX = nullptr, *currX = nullptr;
    Node *prevY = nullptr, *currY = nullptr;
    Node *curr = list;

    while (curr != nullptr) {
        if (curr->data == x) {
            currX = curr;
            break;
        }
        prevX = curr;
        curr = curr->next;
    }

    curr = list;
    
    while (curr != nullptr) {
        if (curr->data == y) {
            currY = curr;
            break;
        }
        prevY = curr;
        curr = curr->next;
    }

    if (currX == nullptr || currY == nullptr) return list;
    
    if (prevX != nullptr) {
        prevX->next = currY;
    } else { 
        list = currY;
    }

    if (prevY != nullptr) {
        prevY->next = currX;
    } else {
        list = currX;
    }

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;

    return list;
}
int main()
{
    int num;
    cout << "Enter 1 ";

    cin >> num;
    if (num == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            insert();
            print();
        }
        swap();
        cout<<"list after swapping 2 nodes";
        print();
    }
}