//merging 2 linked list and sorting them

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

Node *Merge(Node *Root1, Node *Root2)
{
    Node *Root3 = NULL;
    Node *current1 = Root1;

    while (current1 != NULL)
    {
        Node *ptr = new Node();
        ptr->data = current1->data;
        ptr->next = NULL;
        if (Root3 == NULL)
        {
            Root3 = ptr;
        }
        else
        {
            Node *temp = Root3;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
        current1 = current1->next;
    }

    Node *current2 = Root2;

    while (current2 != NULL)
    {

        Node *ptr = new Node();
        ptr->data = current2->data;
        ptr->next = NULL;

        if (Root3 == NULL)
        {
            Root3 = ptr;
        }
        else
        {
            Node *temp = Root3;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }

        current2 = current2->next;
    }

    return Root3;
}
Node *Sort(Node *Root)
{
    Node *sorted = NULL;
    Node *current = Root;

    while (current != NULL)
    {
        Node *next = current->next;
        if (sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    return sorted;
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
    head3 = Sort(head3);
    print(head3);
}
