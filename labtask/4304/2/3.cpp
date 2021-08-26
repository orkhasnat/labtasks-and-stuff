#include <iostream>
#include <stack>
using namespace std;
int ans()
{
    stack<int> post;
    char ch;
    int num, a, b;
    bool end = false;
    while (!end)
    {
        ch = getchar();
        switch (ch)
        {
        case '+':
            b = post.top();
            post.pop();
            a = post.top();
            post.pop();
            num = a + b;
            break;
        case '-':
            b = post.top();
            post.pop();
            a = post.top();
            post.pop();
            num = a - b;
            break;
        case '*':
            b = post.top();
            post.pop();
            a = post.top();
            post.pop();
            num = a * b;
            break;
        case '/':
            b = post.top();
            post.pop();
            a = post.top();
            post.pop();
            num = a / b;
            break;
        case ' ':
            end = true;
            break;
        case '\n':
            end = true;
            break;
        default:
            num = ch - '0';
            break;
        }
        post.push(num);
    }
    return post.top();
}
int main()
{
    int t;
    scanf("%d ",&t); // what is the cin alternative??
    while (t--)
        cout << ans()<<endl;
}