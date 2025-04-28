#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int Stack[10];
int top = 0;

void push(int value)
{

    if (top == 10)
    {
        cout << "Stack overflow";
        return;
    }
    Stack[top] = value;
    top++;
}

int pop()
{
    if (top == 0)
    {
        cout << "Stack underflow";
    }
    else
    {
        top--;
        int popValue = Stack[top] ;
        return popValue;
    }
}

void print()
{
    if (top == 0)
    {
        cout << "Stack is empty\n";
        return;
    }
    for (int i = top - 1; i >= 0; i--)
    {
        cout << Stack[i] << "\n";
    }
}
void Merge(int arr1[], int n1, int arr2[], int n2)
{
    for (int i = 0; i < n1; i++)
    {
        int value = arr1[i];
        push(value);
    }
    for (int i = 0; i < n2; i++)
    {
        int value = arr2[i];
        push(value);
    }
}

int main()
{
    int n1 = 2;
    int n2 = 1;
    int arr1[n1] = {1,2};
    int arr2[n2] = {3};

    int size = n1 + n2;


    int arr[size];
    Merge(arr1, n1, arr2, n2);
    // cout << "Merged array is: \n";
    for (int i = 0; i < size; i++)
    {
        arr[i] = pop();
    }
        reverse(arr, arr + size);
        cout << "Merged array   is: \n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\n";
        }
        cout << "Median is: ";
        float median;
        int mid = size / 2;
        if (size % 2 == 0)
            median = (arr[mid] + arr[mid - 1]) / 2.0;
        else
            median = arr[mid];
        cout << median << "\n";
}
