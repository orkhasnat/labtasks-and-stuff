#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, temp;
    vector<int> arr;
    cin >> t;
    n = t;
    while (t--)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    if (n & 1)
        cout << arr.at(n / 2);
    else
    {
        // even
        int m = n / 2 - 1;
        n = n / 2;
        cout << min(arr.at(m), arr.at(n));
    }
}