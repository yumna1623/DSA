#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

void insert()
{
    Node *ptr = new Node();
    cout << "Enter: ";
    cin >> ptr->data;
    ptr->next = NULL;

    if (head == NULL)
        head = ptr;
    else
    {
        Node *current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = ptr;
    }
}

void print(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void listToArray(Node *head, int arr[], int &size)
{
    Node *current = head;
    while (current != NULL)
    {
        arr[size++] = current->data;
        current = current->next;
    }
}

void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

Node* ArrayToList(int arr[], int size)
{
    Node *newHead = NULL;
    Node *tail = NULL;

    for (int i = 0; i < size; i++)
    {
        Node *ptr = new Node();
        ptr->data = arr[i];
        ptr->next = NULL;

        if (newHead == NULL)
        {
            newHead = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
    }
    return newHead;
}

int main()
{
    const int MAX = 100;
    int array[MAX];
    int size = 0;

    int num;
    cout << "Enter 1 to insert values: ";
    cin >> num;
    if (num == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            insert();
        }

        cout << "Original Linked List: ";
        print(head);

        listToArray(head, array, size);
        reverse(array, size);
        head = ArrayToList(array, size);

        cout << "Reversed Linked List: ";
        print(head);
    }

    return 0;
}
