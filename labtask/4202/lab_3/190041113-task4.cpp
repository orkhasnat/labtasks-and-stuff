#include <iostream>
#define RT 0

#if RT == 1
#include <cmath>
void mathAp()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        int ans = 0;
        while (n > 1)
        {
            long long height = (-1 + std::sqrt(1 + 24 * n)) / 6;
            long long cardNum = (height * (3 * height + 1)) / 2;
            n = n - cardNum;
            ans++;
        }
        std::cout << ans << std::endl;
    }
}
#else
#define NUM 100000 //10e5

int upperBound(long long arr[], int high, int target)
{
    int low = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void DPBS(long long arr[])
{
    int n, result = 0;
    std::cin >> n;
    while (n > 1)
    {
        int h = upperBound(arr, NUM - 1, n);
        h--;
        n = n - arr[h];
        result++;
    }
    std::cout << result << std::endl;
}
#endif

int main()
{
#if RT == 1
    mathAp();
#else
    long long arr[NUM];
    for (long long i = 1; i <= NUM; i++)
        arr[i] = arr[i - 1] + 3 * i - 1;
    int t;
    std::cin >> t;
    while (t--)
        DPBS(arr);
#endif
}