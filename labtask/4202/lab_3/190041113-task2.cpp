#include <iostream>
bool binarySearch(int *arr, int low, int high, int target)
{
    while (low <= high)
    {
        if (arr[low] == target)
            return true;
        if (arr[high] == target)
            return true;
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
    int n, m, k;
    std::cin >> n >> m >> k;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    int low = 0, high = n - 1;
    bool flag;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid][0] <= k && arr[mid][m - 1] >= k)
        {
            flag = binarySearch(arr[mid], 0, m - 1, k);
            break;
        }
        else if (arr[mid][m - 1] < k)
            low = mid + 1;
        else 
            high = mid - 1;
    }

    if (flag)
        std::cout << "True";
    else
        std::cout << "False";
}


// 3 4 30 1 3 6 7 10 11 16 19 20 23 30 32