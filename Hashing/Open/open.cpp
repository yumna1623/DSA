#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int HashFunction(int key, int size)
{
    return key % size;
}
void insert(int size, Node *array[])
{
    cout << "Enter value to insert :";
    int key;
    cin >> key;
    int index = HashFunction(key, size);
    if (array[index] == nullptr)
    {
        Node *newNode = new Node();
        newNode->data = key;
        newNode->next = nullptr;
        array[index] = newNode;
    }
    else
    {
        Node *current = array[index];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        Node *newNode = new Node();
        newNode->data = key;
        newNode->next = nullptr;
        current->next = newNode;
    }
}
void print(int size, Node *array[]){
    for (int i = 0; i < size; i++)
    {
        Node *current = array[i];
        cout << "Index " << i << ": ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
}
void Search(int size, Node *array[])
{
    cout << "Enter the value to search" << endl;
    int key;
    cin >> key;
    int i = 1;
    int index = HashFunction(key, size);
}

int main()
{
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    Node *array[size] = {nullptr};

    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert(size, array);
            break;
        case 2:
            Search(size, array);
            break;
        case 3:
            print(size, array);
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}