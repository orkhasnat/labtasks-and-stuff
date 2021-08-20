#include <iostream>
#include <queue>
using namespace std;
bool sweetness(priority_queue<int> &a, int k, int &op)
{ //returns true if no more op++ is needed
    int m1, m2;
    m1 = -a.top();
    if (m1 >= k)
        return true;
    a.pop();
    m2 = -a.top();
    if (m2 >= k)  // handle : what if there is only one item left m2 will be inaccesible.
    {
        op++;
        return true;
    }
    a.pop();
    int c = m1 + 2 * m2;
    if (c >= k)
    {
        a.push(-c);
        if (a.top() <= k)
        {
            op++;
            return true;
        }
    }
    else
        op++;
    return false;
}
int main()
{
    priority_queue<int> candy;
    int n, k, item, op = 0;
    cin >> n >> k;
    while (n--)
    {
        cin >> item;
        candy.push(-item); // creating min heap
    }
    while (!candy.empty())
    {
        if (sweetness(candy, k, op))
            break;
    }
    (op == 0) ? cout << "-1\n" : cout << op;
}