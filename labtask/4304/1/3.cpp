#include <iostream>
#include <vector>
using namespace std;

int bnIt(vector<int> &op, int n)
{
    int l = 0, r = op.size()-1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (op[m] == n)
            return m;
        if (op[m] < n)
            l = m+1;
        else
            r = m - 1;
    }
    return -1;
}

int bnRc(vector<int> &op, int n, int l, int r)
{   
    if(l<=r){
        int m = (l + r) / 2;
        if(op[m]==n) return m;
        if(op[m]<n) return bnRc(op,n,m+1,r);
        else return bnRc(op,n,l,m-1);
    }
    return -1;
}

int main()
{
    int n, tmp;
    vector<int> input;
    while (cin >> tmp && tmp > -1)
        input.push_back(tmp);
    cin >> n;
    cout << bnIt(input, n) << " (using iteration)\n"
         << bnRc(input, n,0,input.size()-1) << " (using recursion)\n";
}

