// Time Complexity
//     best case: O(n)
//     avarage case: O(n^2)
//     worst case: O(n^2)

#include <iostream>
#include <vector>
#include <algorithm> // swap()
using namespace std;

// compare adjacent elements
// send large element at last
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    bubbleSort(arr);

    cout << "sorted array:\t";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}