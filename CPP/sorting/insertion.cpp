#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
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

    insertionSort(arr);

    cout << "sorted array:\t";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}