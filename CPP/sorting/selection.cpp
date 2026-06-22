// Time Complexity: O(n²) - always, even with sorted input
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            cout << "i = " << i << " , " << "j = " << j << endl;
            if (arr[minIdx] > arr[j])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
        cout << "swapping " << i << " and " << minIdx << endl;
    }
}

int main()
{
    vector<int> arr = {4, 8, 9, 2, 10, 5, 7, 3, 1, 6};
    cout << "unsorted array:\t";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;

    selectionSort(arr);

    cout << "sorted array:\t";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}