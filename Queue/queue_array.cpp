

#include <iostream>
using namespace std;

int front=0;
int size = 0;
int arr[4];

void enqueue()
{
int x;
    cout<<"Enter value to enqueue";
    cin>>x;
    if (size == 4)
    {
        return;
    }

    arr[size] = x;

    size++;
}

void dequeue() {

    if (size == 0) {
        return;
    }

    for (int i = 1; i < size; i++) {
        arr[i - 1] = arr[i];
    }
    size--;
}

int peek()
{
    if (size == 0){
        cout << "Queue is empty." << endl;
    }
    return arr[front];
}

void print() {

    for (int i = front; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool empty(){
    return size == 0;
}
int main()
{
    int values;
    cout << "how many values you want to enqueue/enter";
    cin >> values;
    for (int i = 0; i < values; i++)
    {
        enqueue();
    }

    cout << "Front element: " << peek() << endl;

    cout << "how many values you want to dequeue/remove";
    cin >> values;
    for (int i = 0; i < values; i++)
    {
        dequeue();
    }
    cout << "Front element after dequeue: " << peek() << endl;

    if (empty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }
}
