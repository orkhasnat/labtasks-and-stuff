#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> a) //in a fifo way ie bottom to top
{
    int n = a.size(), j = n;
    cout << "size=" << n << "\t"
         << "items= ";
    int arr[n];
    if (a.empty())
        cout << "NULL";
    while (!a.empty())
    {
        arr[j - 1] = a.top();
        j--;
        a.pop();
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void enqueue(stack<int> &qs)
{
    int item;
    cin >> item;
    qs.push(item);
    print(qs);
}
void dequeue(stack<int> &s1, stack<int> &s2)
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue Empty!!!\n";
        return;
    }
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    print(s1);
}

int main()
{
    int q, cmd;
    stack<int> st1, st2;
    cin >> q;
    while (q--)
    {
        cin >> cmd;
        if (cmd == 1)
            enqueue(st1);
        else if (cmd == 2)
            dequeue(st1, st2);
        else
            cout << "Wrong Command\n";
    }
}