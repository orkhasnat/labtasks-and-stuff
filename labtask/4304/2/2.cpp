#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t; // or we can just write scanf("%d ",&t);
    char ch;
    getchar(); //after taking an integer there is a space or new line that needs to be removed. We dont need to assign getchar to any var because we dont need to use the var later.
    while (t--)
    {
        stack<char> str;
        while (scanf("%c", &ch) && ch != ' ' && ch != '\n') //why scanf instead of cin?? maybe input buffer??
            str.push(ch);
        while (!str.empty())
        {
            cout << str.top();
            str.pop();
        }
        cout << "\n";
    }
}