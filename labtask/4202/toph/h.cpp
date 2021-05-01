#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //******************************************************//
    int t;
    cin >> t;
    while (t--)
    {
        double ad, bc, cd;
        double ans, sqr;
        cin >> bc >> cd >> ad;
        sqr = sqrt(cd * cd + bc * bc);
        ans = ad + sqr;
        cout << sqr << ' ' << ans << endl;
    }
    return 0;
}