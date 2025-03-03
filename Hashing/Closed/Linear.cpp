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
    void Search(int size, int array[])
    {
        cout << "Enter the value to search" << endl;
        int key;
        cin >> key;
        int index = HashFunction(key, size);
        if (array[index] == key)
        {
            cout << "Value found at index" << index << endl;
        }
        else
        {
            for (int i = index + 1; i < size; i++)
            {
                if (array[i] == key)
                {
                    cout << "Value found at index" << i;
                    break;
                }
                if (i == size - 1)
                {
                    for (int j = 0; j < index; j++)
                    {
                        if (array[j] == key)
                        {
                            cout << "Value found at index" << j;
                            break;
                        }
                    }
                }
            }
        }
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

        
        Search(size, array);
        // int choice;
        // cout<<"Enter 1 to insert and 2 to search";
        // cin>>choice;
        // switch (choice)
        // {
        // case1:

        //     break;

        // default:
        //     break;
        // }
    }