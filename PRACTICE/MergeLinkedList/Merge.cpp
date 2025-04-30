#include <iostream>
#include <malloc.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* insert(Node *head) {
    Node *ptr = (Node *)(malloc(sizeof(Node)));
    cout << "Enter: ";
    cin >> ptr->data;
    ptr->next = nullptr;
    if (head == NULL) {
        head = ptr;
        return head;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = ptr;
        return head; 
    }
}

void print(Node *head) {
    Node *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* Merge(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *head3 = NULL, *ptr = NULL;

    if (head1->data < head2->data) {
        head3 = head1;
        head1 = head1->next;
    } else {
        head3 = head2;
        head2 = head2->next;
    }
    ptr = head3;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            ptr->next = head1;
            head1 = head1->next;
        } else {
            ptr->next = head2;
            head2 = head2->next;
        }
        ptr = ptr->next;
    }

    if (head1 == NULL)
        ptr->next = head2;
    else
        ptr->next = head1;

    return head3;
}

int main() {
    int num1, num2;
    cout << "Enter 1st LinkedList size: ";
    cin >> num1;

    Node *head1 = NULL, *head2 = NULL;

    for (int i = 0; i < num1; i++) {
        head1 = insert(head1);
    }
    cout << "1st List: ";
    print(head1);

    cout << "Enter 2nd LinkedList size: ";
    cin >> num2;

    for (int i = 0; i < num2; i++) {
        head2 = insert(head2);
    }
    cout << "2nd List: ";
    print(head2);

    cout << "Merged LinkedList: \n";
    Node *head3 = Merge(head1, head2);
    print(head3);
}
