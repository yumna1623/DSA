








// In a Min-Heap, the parent node is always smaller than or equal to its children.

#include <iostream>
using namespace std;

const int size = 10;
int heap[size];
int heapSize = 0;  

void insert() {
    int key;
    cout << "Enter the value to insert: ";
    cin >> key;

    if (heapSize == size) {
        cout << "Heap is full. Cannot insert." << endl;
        return;
    }

    int i = heapSize;
    heap[i] = key;
    heapSize++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void deleteMin() {
    if (heapSize == 0) {
        cout << "Heap is empty. Cannot delete." << endl;
        return;
    }

    cout << "Deleted Min value: " << heap[0] << endl;

    heap[0] = heap[heapSize - 1];  
    heapSize--;  

    int i = 0;
    while (i < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        
        if (left < heapSize && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heapSize && heap[right] < heap[smallest]) {
            smallest = right;
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
    cout << "Min Heap: ";
    for (int i = 0; i < heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int numValues;

    cout << "How many values do you want to insert into the heap: ";
    cin >> numValues;

    for (int i = 0; i < numValues; i++) {
        insert();
    }

    printHeap();

    deleteMin();
    printHeap();

    return 0;
}




