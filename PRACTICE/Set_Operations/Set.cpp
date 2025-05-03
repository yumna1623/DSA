#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *Root1 = NULL;
Node *Root2 = NULL;

Node *insert(Node *head)
{
    Node *ptr = (Node *)(malloc(sizeof(Node)));

    cout << "Enter the value: ";
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
    return head;
}

void print(Node *Root)
{
    Node *current = Root;
    if (current == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}
void Delete(Node *head)
{

    int toDelete;
    cout << "Enter value to Delete ";
    cin >> toDelete;

    Node *current = head;
    if (head->data == toDelete)
    {
        Node *temp = head;
        Node *current = head;
        head = head->next;
        free(temp);
    }
    else
    {
        Node *prev = head;
        current = head->next;
        while (current != NULL)
        {
            if (current->data == toDelete)
            {
                prev->next = current->next;
                free(current);
                break;
            }
            else
            {
                current = current->next;
                prev = prev->next;
            }
        }
    }
}
int Search(Node *head)
{

    int toSearch;
    cout << "Enter value to search ";
    cin >> toSearch;

    Node *current = head;
    while (current != NULL)
    {
        if (current->data == toSearch)
        {
            cout << "value found";
            return current->data;
        }
        else
        {
            current = current->next;
        }
    }
    cout << "value not found";
}

bool exists(Node *head, int toSearch)
{

    Node *current = head;
    while (current != NULL)
    {
        if (current->data == toSearch)
        {
            return true;
        }
        else
        {
            current = current->next;
        }
    }
    return false;
}

Node *Union(Node *Root1, Node *Root2)
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
        if (!exists(Root3, current2->data))
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
        }
        current2 = current2->next;
    }

    return Root3;
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

Node *Difference(Node *Root1, Node *Root2)
{
    Node *Root3 = NULL;
    Node *current1 = Root1;

    while (current1 != NULL)
    {
        if (!exists(Root2, current1->data))
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
        }
        current1 = current1->next;
    }
    return Root3;
}

Node *Intersection(Node *Root1, Node *Root2)
{
    Node *Root3 = NULL;
    Node *current1 = Root1;

    while (current1 != NULL)
    {
        if (exists(Root2, current1->data))
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
        }
        current1 = current1->next;
    }

    return Root3;
}

Node*Customize(Node *Root1, int Target, int toInsertValue)
{
    Node *Root3 = NULL;

    
    
    Node *current1 = Root1;

    while (current1 != NULL)
    {
        if (current1->data == Target)
        {
            Node *ptr = new Node();
            ptr->data = toInsertValue;
            ptr->next = current1->next;
            current1->next = ptr;
        }
        current1 = current1->next;
    }

    return Root3;
}
int main()
{
    Node *Root3 = NULL;
    cout << "Enter the number of elements in the first set: ";
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        Root1 = insert(Root1);
    }
    cout << "Enter the number of elements in the second set: ";
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        Root2 = insert(Root2);
    }

    int choice;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Display First Set\n";
        cout << "2. Display Second Set\n";
        cout << "3. Union\n";
        cout << "4. Intersection\n";
        cout << "5. Difference (First - Second)\n";
        cout << "6. Merge\n";
        cout << "7. Customize Insert\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "The first set is: ";
            print(Root1);
            break;

        case 2:
            cout << "The second set is: ";
            print(Root2);
            break;

        case 3:
            Root3 = Union(Root1, Root2);
            Root3 = Sort(Root3);
            cout << "The union of the two sets is: ";
            print(Root3);
            break;

        case 4:
            Root3 = Intersection(Root1, Root2);
            cout << "The intersection of the two sets is: ";
            print(Root3);
            break;

        case 5:
            Root3 = Difference(Root1, Root2);
            cout << "The difference (First - Second) is: ";
            print(Root3);
            break;

        case 6:
            Root3 = Merge(Root1, Root2);
            Root3 = Sort(Root3);
            cout << "The merged and sorted set is: ";
            print(Root3);
            break;

        case 7:
        //for 2nd set please enter 0
            int Target, toInsertValue;
            cout << "Enter value after which you want to insert: ";
            cin >> Target;
            cout << "Enter value to insert: ";
            cin >> toInsertValue;
            Root1 = Customize(Root1, Target, toInsertValue);
            cout << "Updated first set: ";
            print(Root1);
            break;

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }

    } while (choice != 8);

}
