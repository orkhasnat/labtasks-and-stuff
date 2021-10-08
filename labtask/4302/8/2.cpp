#include <iostream>
#include <algorithm>
using std::cout, std::cin, std::endl;

template <typename T>
T amax(T arr[], int size, int n)
{
    std::sort(arr, arr + size);
    return arr[n - 1];
}

int main()
{
    int arr[10] = {1, 2, 5, 6, 9, 8, 7, 4, 0, 3};
    cout << amax(arr, 10, 3);
}