#include<iostream>
using namespace std;

void selectionSort(){

    int arr[5] ={ 76,45,32,12,1};	// 1 12 32 45 76 
    int size = 5;
    for(int i=0; i<5; i++){
        int min = i;
        for (int j = i+1; j < 5; j++)
        {
            if(arr[i]>arr[j]){
                min = j;
        }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
}
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    

selectionSort();
}
    
    

