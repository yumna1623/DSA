#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insert(Node *head)
{
    Node *ptr = new Node();
    cout << "Enter: ";
    cin >> ptr->data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return head;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = ptr;
        return head;
    }
}

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

int reverseDigits(int num)
{
    int rev = 0;
    while (num != 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

Node *createReversedList(Node *head)
{
    Node *current = head;
    Node *newList = NULL;
    while (current != NULL)
    {
        Node *ptr = new Node();
        ptr->data = reverseDigits(current->data);
        ptr->next = NULL;
        if (newList == NULL)
        {
            newList = ptr;
        }
        else
        {
            Node *temp = newList;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
        current = current->next;
    }
    return newList;
}

Node *Merge(Node *Root1, Node *Root2)
{
    Node *Root3 = NULL;
    Node *tail = NULL;

    Node *current1 = Root1;
    while (current1 != NULL)
    {
        Node *ptr = new Node();
        ptr->data = current1->data;
        ptr->next = NULL;
        if (Root3 == NULL)
        {
            Root3 = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
        current1 = current1->next;
    }

    Node *current2 = Root2;
    while (current2 != NULL)
    {
        Node *ptr = new Node();
        ptr->data = current2->data;
        ptr->next = NULL;
        tail->next = ptr;
        tail = ptr;
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

int main()
{
    int num1, choice;
    cout << "Enter 1st LinkedList size: ";
    cin >> num1;

    Node *LL1 = NULL, *LL2 = NULL, *MergedList = NULL;

    for (int i = 0; i < num1; i++)
    {
        LL1 = insert(LL1);
    }

    LL2 = createReversedList(LL1);

    do
    {
        cout << "\n1) Print 1st List (it will be Sorted)" << endl;
        cout << "2) Print 2nd List (Digit-wise Reversed)" << endl;
        cout << "3) Merge and Print both Lists LL1 and LL2 " << endl;
        cout << "4) Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            LL1 = Sort(LL1);
            cout << "Sorted 1st List: ";
            print(LL1);
            break;
        case 2:
            cout << "2nd List (Digit-wise Reversed): ";
            print(LL2);
            break;
        case 3:
            MergedList = Merge(LL1, LL2);
            MergedList = Sort(MergedList);
            cout << "Merged and Sorted List: ";
            print(MergedList);
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);
}
