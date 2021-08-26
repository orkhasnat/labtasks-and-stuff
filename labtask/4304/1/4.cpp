#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<int> op;
    while (cin >> n && n != 0)
        op.push_back(n);
    cin >> n;
    int len = op.size(), c = 0;
    pair<int, int> a[len * (len - 1)]; //possible number of pairs
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (i != j && op[i] + op[j] == n)
            {
                a[c].first = i + 1, a[c].second = j + 1;
                c++;
            }
        }
    }
    if (c==0){
        cout<<"No pair found";
        return 0;
    }
    cout << c << " Pairs:\n";
    for (int i = 0; i < c; i++)
        printf("(worker-%d, worker-%d)\n", a[i].first, a[i].second);
}