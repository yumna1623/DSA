#include <iostream>
using namespace std;



void bubbleSort(int arr[] , int n){
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int arr[5] = {43, 23, 12, 45, 67};
    int n = 5;

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout<<"Array after sorting: ";
    bubbleSort(arr, n);
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
