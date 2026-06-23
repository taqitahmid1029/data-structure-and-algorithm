#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        if (arr[mid1] == target)
        {
            return mid1;
        }
        else if (arr[mid2] == target)
        {
            return mid2;
        }
        else if (arr[mid1] > target)
        {
            right = mid1 - 1;
        }
        else if (arr[mid1] < target && target < arr[mid2])
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
        else if (arr[mid2] < target)
        {
            left = mid2 + 1;
        }
    }
}

int main()
{
    vector<int> arr = {3, 5, 7, 9, 34, 56, 61, 62, 92};
    cout << ternarySearch(arr, 56) << endl;

    return 0;
}