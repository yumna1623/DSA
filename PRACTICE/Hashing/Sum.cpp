#include <iostream>
using namespace std;

int HashFunction(int key, int size)
{
    return key % size;
}
void insert(int size, int array[])
{
    cout << "Enters value to insert";
    int key;
    cin >> key;
    int index = HashFunction(key, size);
    if (array[index] == -1)
    {
        array[index] = key;
    }
    else
    {
        for (int i = index + 1; i < size; i++)
        {
            if (array[i] == -1)
            {
                array[i] = key;
                break;
            }
            if (i == size - 1)
            {
                for (int j = 0; j < index; j++)
                {
                    if (array[j] == -1)
                    {
                        array[j] = key;
                        break;
                    }
                }
            }
        }
    }
    
}
void ToFindSumOfTwoValues(int array[], int size, int target){

    for (int i = 0; i < size; i++)
    {
        for(int j=i+1; j<size; j ++){
            if(array[i]+array[j]==target){
                cout<<"The two values are "<<array[i]<<" and "<<array[j]<<endl;
                cout<<" Indexes are "<<i <<" ,"<< j;
                return;
            }
        }

    }

    cout<<"No such values found"<<endl;
    
}
void print(int array[], int size){
    cout << "The values in the array are: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
    

    int main()
    {
        int size;
        cout << "Enter how many values you want to add";
        cin >> size;
        int array[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
        }
        
        for (int i = 0; i < size; i++)
        {
            insert(size, array);
        }
        print(array, size);
        cout<<"Enter targte value ";
        int target;
        cin>>target;
         ToFindSumOfTwoValues(array, size, target);


        
        
        
    }