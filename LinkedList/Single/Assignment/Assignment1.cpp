#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *list = NULL;

void insert() {
    Node *ptr = (Node *)(malloc(sizeof(Node)));

    cout << "Enter: ";
    cin >> ptr->data;
    ptr->next = NULL;

    if (list == NULL) {
        list = ptr;
    } else {
        Node *current = list;
        int count = 0;
        int modValue = ptr->data % 3;

        while (current->next != NULL) {
            count++;
            if ((modValue == 0 && count % 3 == 0) ||   // Insert at end
            (modValue == 1 && count % 1 == 0) ||   // Insert after every 1 node
            (modValue == 2 && count % 2 == 0)) {   // Insert after every 2 nodes
                
                Node *temp = new Node();
                temp->data = ptr->data;
                temp->next = current->next;
                current->next = temp;
                current = temp;
            }
            current = current->next;
        }
        current->next = ptr;
    }
}
void print()
{
    Node *current = list;
    do{
        cout << current->data;
        current = current->next;
    }
    while (current != list);
    
}

int main() {
    int n;
    cout << "How many numbers do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        insert();
        print();
    }
    return 0;
}
