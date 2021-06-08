#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

//T- primes are squares of primes

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //**************************************//

    int t;
    bool f = 0;
    cin >> t;
    long long int a ;
    //int prime[ceil(sqrt(t))
    while (t--)
    {


        f = 0;
        cin >> a;

        // cout<< j;

        double j = sqrt(a);
        if (a == 1 || j - (int)j != 0)
            cout << "NO\n";
        else
        {
            for (int k = 2; k * k <= j; k++)
            {
                if ((int)j % k == 0)
                {
                    f = 1;
                    break;
                }
                //cout<< j;
            }

           if (f == 1)
                cout << "NO\n";
            else
                cout << "YES\n";
        }


    }

}
