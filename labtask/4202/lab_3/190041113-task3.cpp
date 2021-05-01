#include <iostream>

void search(int arr[], int n, int t)
{
    int low = 0, mid, high = n - 1, first = -1, last = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == t)
        {
            first = mid;
            last = mid;
            break;
        }
        else if (arr[mid] > t)
            high = mid - 1;
        else
            low = mid + 1;
    } 
    if (first != -1 && last != -1)
    {
        while (first - 1 >= 0)
        {
            if (arr[first - 1] == t)
                first--;
            else
                break;
        }
        while (last + 1 < n)
        {
            if (arr[last + 1] == t)
                last++;
            else
                break;
        }
        if (first == last)
            std::cout << t << " occurs only once at position:  " << first << std::endl;
        else
            std::cout << "First occurence of element " << t << " is at position:  " << first << "\nLast occurence of element " << t << " is at position:  " << last << std::endl;
    }
    //else if(first==last) ;
    else
        std::cout << t << " not found\n";
}

int main()
{
    int n, t;
    std::cin >> n >> t;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    search(arr, n, t);
}