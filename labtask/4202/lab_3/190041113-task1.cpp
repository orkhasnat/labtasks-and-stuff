#include <iostream>
#include <algorithm>

bool binarySearch(int arr[], int low, int high, int target)
{
    std::sort(arr, arr + high);
    high = high - 1;
    while (low <= high)
    {
        if(arr[low]==target) return true;
        if(arr[high]==target) return true;
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
} 
int main()
{
    int n, k;
    std::cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    if (binarySearch(arr, 0, n, k))
        std::cout << "Found";
    else
        std::cout << "Not Found";
}

// @ O(log n) complexity??