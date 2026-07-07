#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target < arr[mid])
        {
            right = mid - 1;
        }
        else if (target > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
}

int main()
{
    int arr[] = {3, 5, 8, 12, 27, 35, 62, 94};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", binarySearch(arr, n, 35));
    return 0;
}