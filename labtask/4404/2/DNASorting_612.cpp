#include <bits/stdc++.h>
using namespace std;

struct DNA
{
    int position;
    int inversion;
};
int getInversion(const string &s)
{
    int in = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[i] > s[j])
                in++;
        }
    }
    return in;
}
bool comparator(const DNA &a, const DNA &b)
{
    if (a.inversion == b.inversion)
        return a.position < b.position;
    return a.inversion < b.inversion;
}

void solve(int len, int count)
{
    DNA arr[count];
    string str[count];
    for (int i = 0; i < count; i++)
    {
        cin >> str[i];
        arr[i].position = i;
        arr[i].inversion = getInversion(str[i]);
    }
    sort(arr, arr + count, comparator);
    for (int i = 0; i < count; i++)
        cout << str[arr[i].position] << endl;
}

int main()
{
    int t, m, n;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        solve(n, m);
        if (t)
            cout << endl;
    }
}
