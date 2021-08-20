#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> a)
{
    cout << "size=" << a.size() << "\t"
         << "items= ";
    if (a.empty())
        cout << "NULL";
    while (!a.empty())
    {
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
}
int main()
{
    int n, og = 1, it;
    stack<int> sd;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> it;
        if (it == og)
            og++;
        else
        {
            if (!sd.empty() && og ==sd.top())
            {
                sd.pop();
                og++;
            }
            sd.push(it);
        }
        //print(sd);
    }
    while (!sd.empty())
    {   
        //print(sd);
        if (og == sd.top())
        {
            og++;
            sd.pop();
        }
        else  break;
    }
    if (og == n+1)
        cout << "Yes\n";
    else
        cout << "No\n";
}

// check this 5 2 1 4 3 6 should be yes!!
// 6 shouldnt enter the stack but it does which is a problem