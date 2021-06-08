#include <bits/stdc++.h>
using namespace std;

int max(int index)
{
    int arr[] = {7, 25, 59, 49, 13, 117, -12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxi = arr[0];

    if (arr[index] > maxi)
        maxi = arr[index];
    if (index == (n - 1))
        return maxi;
    else
        return max(index + 1);
}

int main()
{

    //int maxi = arr[0];

    cout << max(0);
}
