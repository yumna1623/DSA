#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *list = NULL;
Node *reverseList = NULL;
int Stack[4];
int top = 0;

void push(int data) {
    if (top == 4) {
        cout << "Stack overflow\n";
        return;
    }
    Stack[top] = data;
    top++;
}

Node* pop() {
    for (int i = top - 1; i >= 0; i--) {
        Node *newNode = new Node;
        newNode->data = Stack[i];
        newNode->next = NULL;
        newNode->prev = NULL;

        if (reverseList == NULL) {
            reverseList = newNode;
        } else {
            Node *current = reverseList;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
    return reverseList;
}

void printReverseList() {
    Node *current = reverseList;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void insert() {
    Node *ptr = new Node;
    cout << "Enter data to insert node: ";
    cin >> ptr->data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (list == NULL) {
        list = ptr;
        return;
    }

    if (ptr->data < list->data) {
        ptr->next = list;
        list->prev = ptr;
        list = ptr;
        return;
    }

    Node *current = list;
    while (current->next != NULL && current->next->data < ptr->data) {
        current = current->next;
    }

    ptr->next = current->next;
    if (current->next != NULL)
        current->next->prev = ptr;

    current->next = ptr;
    ptr->prev = current;

}

void print() {
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
        print();
    }

    cout << "Sorted List: ";
    print();

    Node*current = list;
    while (current != NULL) {
        push(current->data);
        current = current->next;
    }

    cout << "Copying the reversed list to new list...\n";

    cout << "Reversed List: ";
    pop();
    printReverseList();
}
