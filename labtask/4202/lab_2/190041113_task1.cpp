#include <iostream>
#include <algorithm> 

bool bubblesort(int n, int arr[])
{
    bool a = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j + 1], arr[j]);
                a = true;
            }
        }
    }
    return a;
}

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    if (bubblesort(n, arr))
    {
        std::cout << "No" << std::endl;
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
    }
    else
        std::cout << "Yes" << std::endl;
}
