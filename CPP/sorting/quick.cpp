#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int idx = start - 1;
    int pivot = arr[end];
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            idx++;
            swap(arr[idx], arr[i]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivIdx = partition(arr, start, end);
        quickSort(arr, start, pivIdx - 1);
        quickSort(arr, pivIdx + 1, end);
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

    quickSort(arr, 0, arr.size() - 1);

    cout << "sorted array:\t";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}