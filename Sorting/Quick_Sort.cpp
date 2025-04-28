#include<iostream>
using namespace std;

int setPivot(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2];
    int l = low;
    int r = high;

    while (l <= r) {
        while (arr[l] < pivot) {
            l++;
        }
        while ( pivot < arr[r]) {
            r--;
        }
        if (l <= r) {
            int hold = arr[l];
            arr[l] = arr[r];
            arr[r] = hold;
            l++;
            r--;
        }
    }
    return l;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = setPivot(arr, low, high);
        QuickSort(arr, low, pi - 1);   // left partition
        QuickSort(arr, pi, high);    // right partition
    }
}
int main() {
    int arr[5] = {43, 23, 12, 45, 27}; // 12 23 27 43 45
    int size = 5;
    QuickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
