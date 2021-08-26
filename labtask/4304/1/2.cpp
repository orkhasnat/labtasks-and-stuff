#include <iostream>
using namespace std;
#define ll long long
ll factIt(int n)
{
    ll ans = 1;
    while (n>1)
    {
        ans*=n;
        n--;
    }
    return ans;
}
ll factRc(int n)
{
    if(n<2) return 1;
    return n*factRc(n-1);
}
int main()
{
    int n;
    cin >> n;
    cout << factIt(n) << " (using iteration)\n"
         << factRc(n) << " (using recursion)\n";
}
