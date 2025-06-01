#include <iostream>
using namespace std;

int HashFunction(int key, int size)
{
    return key % size;
}
void insert(int size, int array[])
{
    cout << "Enter value to insert :";
    int key;
    cin >> key;
    int index = HashFunction(key, size);
    int i = 1;
    if (array[index] == -1)
    {

        array[index] = key;
    }
    else if (array[index] != -1)
    {
        int newIndex = (index + i * i) % size;
        if (array[newIndex] == -1)
        {
            array[newIndex] = key;
        }
        else
        {
            for (int i = index + 1; i < size; i++)
            {
                newIndex = (index + i * i) % size;
                if (array[newIndex] == -1)
                {
                    array[newIndex] = key;
                    break;
                }
            }
        }

        for (int i = index + i; i < size; i++)
        {
            if (i == size)
            {
                cout << "Hash table is full, cannot insert " << key << endl;
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
void print(int size, int array[])
{
    cout << "values in array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " " << endl;
    }
}
void Search(int size, int array[])
{
    cout << "Enter the value to search" << endl;
    int key;
    cin >> key;
    int i = 1;
    int index = HashFunction(key, size);
    if (array[index] == key)
    {
        cout << "Value found at index :" << index << endl;
    }
    else
    {
        for (int i = index + 1; i < size; i++)
        {
            int newIndex = (index + i * i) % size;
            if (array[newIndex] == key)
            {
                cout << "Value found at index :" << newIndex << endl;
                break;
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
        print(size, array);
    }

    for (int i = 0; i < size; i++)
    {
        Search(size, array);
    }
}