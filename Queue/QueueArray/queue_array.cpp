#include <iostream>
using namespace std;

int front = 0;
int size = 0;
int arr[4];

void enqueue() {
    int x;
    cout << "Enter value to enqueue: ";
    cin >> x;
    if (size == 4) {
        cout << "Queue is full." << endl;
        return;
    }

    arr[size] = x;
    size++;
}

void dequeue() {
    if (size == 0) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    for (int i = 1; i < size; i++) {
        arr[i - 1] = arr[i];
    }
    size--;
}

int peek() {
    if (size == 0) {
        cout << "Queue is empty." << endl;
        return -1; 
    }
    return arr[front];
}

void print() {
    if (size == 0) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool empty() {
    return size == 0;
}

int main() {
    int values;
    cout << "How many values you want to enqueue: ";
    cin >> values;
    for (int i = 0; i < values; i++) {
        enqueue();
    }

    print();

    int frontElement = peek();
    if (frontElement != -1) {
        cout << "Front element: " << frontElement << endl;
    }

    cout << "How many values you want to dequeue: ";
    cin >> values;
    for (int i = 0; i < values; i++) {
        dequeue();
    }

    print();

    frontElement = peek();
    if (frontElement != -1) {
        cout << "Front element after dequeue: " << frontElement << endl;
    }

    if (empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
}
