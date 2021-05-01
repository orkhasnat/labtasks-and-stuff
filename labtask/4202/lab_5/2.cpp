#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define push_back pb

int main()
{ // the sum of x numbers can only be odd if we have an odd number of numbers which are odd.
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n+1], state[2]; state[0]=state[1]=0;
        for (int i = 1; i <= n; i++)
        { 
            cin >> arr[i];
            state[arr[i] % 2]++;
        }
        bool f = 0;
        for (int i = 1; i <= state[1] && i <= x; i = i + 2)
        {
            int t = x - i;
            if (t <= state[0])
                f = 1;
        }
        f==1 ? cout<<"Yes\n" : cout << "No\n"; 
    }
}