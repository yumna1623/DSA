#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

// Function to insert at end
void insert()
{
    Node *ptr = new Node();
    cout << "Enter: ";
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

// Function to print list
void print(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to convert list to array
void listToArray(Node *head, int arr[], int &size)
{
    Node *current = head;
    while (current != NULL)
    {
        arr[size++] = current->data;
        current = current->next;
    }
}

// Function to reverse the array
void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Function to convert array to linked list
Node *ArrayToList(int arr[], int size)
{
    Node *newHead = NULL;
    Node *current = NULL;

    for (int i = 0; i < size; i++)
    {
        Node *ptr = new Node();
        ptr->data = arr[i];
        ptr->next = NULL;

        if (newHead == NULL)
        {
            newHead = ptr;
            current = ptr;
        }
        else
        {
            current->next = ptr;
            current = current->next;
        }
    }

    return newHead;
}

int main()
{
    int num;
    cout << "Enter 1 to insert values: ";
    cin >> num;

    if (num == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            insert();
        }

        cout << "Original List: ";
        print(head);

        // Convert to array
        int arr[100]; 
        int size = 0;
        listToArray(head, arr, size);

        // Reverse array
        reverse(arr, size);

        head = ArrayToList(arr, size);

        cout << "Reversed List: ";
        print(head);
    }

}