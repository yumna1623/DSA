#include <iostream>
using namespace std;

const int size = 10;

struct Task {
    string name;
    int priority;
};

Task heap[size];
int heapSize = 0;

void insertTask() {
    Task t;
    cout << "Enter Task Name: ";
    cin >> t.name;
    cout << "Enter Task Priority (smaller number = higher priority): ";
    cin >> t.priority;

    if (heapSize == size) {
        cout << "Heap is full. Cannot insert." << endl;
        return;
    }

    int i = heapSize;
    heap[i] = t;
    heapSize++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i].priority < heap[parent].priority) {
            swap(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void DeleteMin() {
    if (heapSize == 0) {
        cout << "Heap is empty. Cannot delete." << endl;
        return;
    }

    heap[0] = heap[heapSize - 1];
    heapSize--;

    int i = 0;
    while (i < heapSize) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        if (leftChild < heapSize && heap[leftChild].priority < heap[smallest].priority) {
            smallest = leftChild;
        }
        if (rightChild < heapSize && heap[rightChild].priority < heap[smallest].priority) {
            smallest = rightChild;
        }
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}


void printHeap() {
    cout << "Min Heap (Tasks): ";
    for (int i = 0; i < heapSize; i++) {
        cout << "[" << heap[i].name << " " << heap[i].priority << "] ";
    }
    cout << endl;
}

int main() {
    int numTasks;
    cout << "How many tasks do you want to insert into the heap: ";
    cin >> numTasks;

    for (int i = 0; i < numTasks; i++) {
        insertTask();
    }

    printHeap();
    DeleteMin();
    cout << "After deleting the task with the highest priority:" << endl;
    printHeap();
}