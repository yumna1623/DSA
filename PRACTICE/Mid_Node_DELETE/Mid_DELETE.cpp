#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
Node *prev = NULL;
int current;

void insert()
{
    Node *ptr = (Node *)(malloc(sizeof(Node)));
    cout << "Enter";
    cin >> ptr->data;
    ptr->next = nullptr;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = ptr;
    }
}

void print()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data;
        cout << "\n";
        current = current->next;
        cout << " ";
    }
}
void Delete() {
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL) {
        prev->next = slow->next;
    } else {
        head = head->next;
    }

    cout << "Deleted node with value: " << slow->data << endl;
    free(slow);
}

int main()
{
    
        for (int i = 0; i < 4; i++)
        {
            insert();
            print();
        }
        Delete();
        cout << "After deleting the middle node" << endl;
        print();
}



















