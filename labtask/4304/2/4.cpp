#include <iostream>
#include <string>
#include <stack>
using namespace std;
void print(stack<char> a)
{
    cout << "size=" << a.size() << "\t"
         << "items= ";
    if (a.empty())
        cout << "NULL";
    while (!a.empty())
    { // because stack is already empty so it will not enter loop
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
}
bool solve()
{
    string str;
    cin >> str;
    stack<char> ls;
    char a;
    for (auto ch : str)
    {
        if (ch == '[' || ch == '{' || ch == '(')
        {
            ls.push(ch);
            continue;
        }
        if (!ls.empty())
        {
            switch (ch)
            {
            case ']':
                a = ls.top();
                if (a == '{' || a == '(')
                    return false;
                else
                    ls.pop();
                break;
            case ')':
                a = ls.top();
                if (a == '{' || a == '[')
                    return false;
                else
                    ls.pop();
                break;
            case '}':
                a = ls.top();
                if (a == '[' || a == '{')
                    return false;
                else
                    ls.pop();
                break;
            default:
                break;
            }
        }
        else
            return false;
        //print(ls);
    }
    return ls.empty();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve() ? cout << "Yes\n" : cout << "No\n";
}

// 8
// [ 5 + (2 x 5) - (7 / 2) ]
// [ 1 + { 3 x (2 / 3 ) ] } ...
// [ ( 1 + 1 ) ]
// [ ( 1 + 1 ] ) ....
// [ ( ) ] { } { [ ( ) ( ) ] ( ) } ...
// ( ( (
// [ 5 + (2 x 5) - (7 / 2)
// 5 + (2 x 5) - (7 / 2) ]
// ()))
// Yes
// No
// Yes
// No
// Yes
// No
// No
// No
// No
