#include<iostream>
using namespace std;

int main(){
    int arr [5] = {43, 23, 12, 45, 67};

    for(int i=1;i<5;i++){
        int current = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }




    
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}
