#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {  
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued." << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty, cannot dequeue." << endl;
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;  
    }

    cout << temp->data << " dequeued." << endl;
    delete temp;
}

void peek() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

void printQueue() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isEmpty() {
    return front == NULL;
}

int main() {
    int values;
    cout << "How many values you want to enqueue: ";
    cin >> values;

    for (int i = 0; i < values; i++) {
        int x;
        cout << "Enter value: ";
        cin >> x;
        enqueue(x);
    }

    printQueue();
    peek();

    cout << "How many values you want to dequeue: ";
    cin >> values;

    for (int i = 0; i < values; i++) {
        dequeue();
    }

    printQueue();
    peek();

    if (isEmpty()) {
        cout << "Queue is empty now." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
