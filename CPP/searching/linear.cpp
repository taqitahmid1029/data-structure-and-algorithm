#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
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
    vector<int> arr = {4, 8, 9, 2, 10, 5, 7, 3, 1, 6};
    cout << linearSearch(arr, 7) << endl;
    return 0;
}