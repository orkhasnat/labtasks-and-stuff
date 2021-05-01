#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int n, k;
        cin >> n >> k;
        int full = n - (n % k);
        full = full + min(n % k, k / 2);
        cout << full << endl;
    }
    return 0;
}