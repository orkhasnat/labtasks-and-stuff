//#############################what the fuck was even doing##########################
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
/*
int MOD(ll x){
    if(x<1024) return x;
    else if (x>100000) 
}

int big_mod(int base, int power, int mod)
{
    if(power==0)    return 1;
    //কোন কিছুর power 0 হলে তার মান 1 হয়ে যায়
    else if(power%2==1) //power বেজোড় হলে
    {
        int p1 = base % mod;
        int p2 = (big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2==0) //power জোড় হলে
    {
        int p1 = (big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}

void solve(){
    ll ans;
        ll rem = big_mod(2,1,7);
        ll mod= n/7;
        //cout<<mod<<' '<<rem<<endl;
        ans=mod*2+mod*7;
        if(rem<=3) ans+=rem;
        else if(rem==4) ans+=rem+1;
        else ans+=rem+2;
        cout<<ans<<endl;
}
*/
// void solve(vector<int> &n)
// {
//     ll ans;
//     ll rem = remnder(n);
//     ll mod = rem;
// }

// int remnder(vector<int> &s)
// {
//     int rem = 0;
//     for (int i = 0; i < s.size(); ++i)
//         rem = (rem * 10 + s[i]) % 7;
//     return rem;
// }
ll vec2ll(vector<int> &n)
{
    ll num = 0, tm = 1;
    for (auto i = n.end(); i != n.begin(); i--)
    {
        num += (*i) * tm;
        tm *= 10;
    }
    return num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //******************************************************//
    int t;
    cin >> t;
    while (t--)
    {
        std::vector<int> n;
        n.reserve(100);
        char p;
        do
        {
            scanf("%c", &p);
            n.push_back(p - '0');
        } while (p != '\n');
        n.pop_back();
        //solve(n);
        cout << vec2ll(n);
    }
    return 0;
}



