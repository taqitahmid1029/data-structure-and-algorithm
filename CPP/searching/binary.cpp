// requirements: sorted array
// time complexity: O(logn)

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) // iteration method
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        // int mid = (left + right) / 2;
        int mid = left + (right - left) / 2;

        if (arr[mid] > target)
            right = mid - 1;

        else if (arr[mid] < target)
            left = mid + 1;

        else // arr[mid] == target
            return mid;
    }
    return -1;
}

int binarySearchREC(vector<int> arr, int left, int right, int target) // recursive method
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] > target)
        return binarySearchREC(arr, left, mid - 1, target);

    else if (arr[mid] < target)
        return binarySearchREC(arr, mid + 1, right, target);

    else // arr[mid] == target
        return mid;
}

int main()
{
    vector<int> arr = {3, 5, 7, 9, 34, 56, 61, 62, 92};
    cout << binarySearch(arr, 34) << endl;
    cout << binarySearchREC(arr, 0, arr.size() - 1, 34);
    return 0;
}