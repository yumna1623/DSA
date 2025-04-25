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

Node* ReverseList() {
    if (list == NULL) return list;

    
    
    Node*ptr1 = list;
    Node*ptr2 = list->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while(ptr2 != NULL) {
    


        while(ptr2!=NULL){
            Node*temp = ptr2->next;
            ptr2->next = ptr1;
            ptr2->prev = temp;
            ptr1 = ptr2;
            ptr2 = temp;
        }
        
        
    }
    
    list = ptr1;
    return list;

}


Node* MinNode() {
    if (list == NULL) return list;

    Node*current = list;
    Node* minNode = list;
    while(current!=NULL){
        if(current->data < minNode->data){
            minNode = current;
        }
        current = current->next;
    }
    return minNode;
}
Node* Maxnode(Node *list) {
    if (list == NULL) return list;

    Node* maxNode = list;
    Node* current = list;
    while(current!=NULL){
        if(current->data > maxNode->data){
            maxNode = current;
        }
        current = current->next;
    }
    return maxNode;
}

void print()
{
    Node *current = list;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}



int main() {
    cout << "Insert 4 nodes:\n";
    for (int i = 0; i < 4; i++) {
        insert();
    }

    cout << "Original List: ";
    print();

    ReverseList();
    cout << "Reversed List: ";
    print();

    Node* minNode = MinNode();
    cout << "Minimum Node Value: " << minNode->data << endl;

    Node* maxNode = Maxnode(list);
    cout << "Maximum Node Value: " << maxNode->data << endl;

}
