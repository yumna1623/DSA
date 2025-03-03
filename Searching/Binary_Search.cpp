#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 3, 4};
    int left = 0;
    int right = 5;
    int mid, toSearch = 3;
    int counter = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == toSearch)
        {
            counter++;
            cout << "Element " << toSearch << " found at index " << mid<<endl;
            if (arr[mid] > toSearch)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (arr[mid] < toSearch)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (counter > 0)
    {
        cout << "Total occurrences of " << toSearch << ": " << counter << endl;
    }
    else
    {
        cout << "Element " << toSearch << " not found" << endl;
    }
}
