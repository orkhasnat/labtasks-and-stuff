// incomplete
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    stack<char> st;
    int r = 0, l = 0, ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ']')
        {
            r++;
        }
        else
        {
            st.push(str[i]);
            l++;
            if (str[i + 1] == ']')
            {
                st.pop();
                i++;
                l--;
            }
        }
    }
    cout << l+r;
}
