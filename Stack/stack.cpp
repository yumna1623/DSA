#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = NULL;


bool isempty()
{
    if(top == NULL)
    {
        cout << "the stack is empty";
        return true;
    }
    else
    {
        cout << "the stack is not empty";
        return false;
    
void push()
{
    Node *ptr = (Node *)(malloc(sizeof(Node)));
    
    cout << "Enter the element to be added: ";
    cin >> ptr->data;
    ptr->next = top;
        top = ptr;
        
        cout << "Pushed: " << ptr->data << endl;
}
int pop()
{
    
    if (isempty())
    {
        cout << "the stack is empty";
        return -1;
    }
    
        Node *temp = top;
        int value = top->data;
        top = top->next;
        free(temp);
        return value;
    
}
int peek() 
{
    if (isempty())
    {
        cout << "the stack is empty";
        return -1;
    }
    else
    {
        return top->data;
    }
}

bool isfull() { return false; }

void print() 
{
    Node *current = top;
    if (isempty())
    {
        cout << "no element ";
    }
    
        while (current != NULL)
        {
            cout << current->data << "  ";
            current = current->next;
        }
        cout << endl;
    
}

int main()
{
    int values;
    cout << "how many values you want to push/enter";
    cin >> values;
    for (int i = 0; i < values; i++)
    {
        push();
    }

    cout << "Top element: " << peek() << endl;

    cout << "how many values you want to pop/remove";
    cin >> values;
    for (int i = 0; i < values; i++)
    {
        pop();
    }
    cout << "top element after pop: " << peek() << endl;

    if (isempty())
    {
        cout << "stack is empty." << endl;
    }
    else
    {
        cout << "stack is not empty." << endl;
    }

    
}