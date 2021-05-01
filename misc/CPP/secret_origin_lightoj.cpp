#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// this is a mess
vector<int> dec2bin(int n)

    int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //******************************************************//
    int t, n, s1, s2;
    cin>> t;

    while (t--)
    {
        cin >> n;
        s1 = 0;
    }

    return 0;
}

vector<int> dec2bin(int n)
{
    int a = n;
    vector<int> bin;
    for (int i = 0; a > 0; i++)
    {
        bin.push_back(a%2);
        a=a/2;
    }
    return bin;
}

void binaryadd()
{
}