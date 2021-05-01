#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string k;
    cin >> n >> k;
    //cout << n << k;

    int r = 0;
    char ans[3];
    for (int i = 0; i < n - 1; i++)
    {
        int c = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (k[j] == k[i] && k[j + 1] == k[i + 1])
                c++;

            if (r < c)
            {
                r = c;
                //ans = string(1, k[i]) + string(1, k[i + 1]);
                ans[0]= k[i];
                ans[1] = k[i+1];
                ans[2] ='\0';
            }
        }
    }

    cout << ans << endl;

    return 0;
}