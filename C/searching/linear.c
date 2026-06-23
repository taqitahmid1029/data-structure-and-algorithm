#include <stdio.h>

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4, 6, 23, 45, 2, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("%d", linearSearch(arr, length, 23));
    return 0;
}