#include <iostream>
using namespace std;

int arrSize;
// int size()
// {
//     return arrSize;
// }
// bool isEmpty()
// {
//     if (arrSize == 0)
//         return true;
//     return false;
// }
void push(int *stack, int cap)
{
    if (arrSize == cap)
    {
        cout << "Overflow" << endl;
        return;
    }
    int item;
    cin >> item;
    stack[arrSize++] = item;
}
void pop()
{
    if (arrSize == 0)
        return;
    arrSize--;
}
void print(int *stack)
{
    cout << "size=" << arrSize << "\t"<<"items= ";
    if (arrSize == 0)
        cout << "NULL";
    for (int i = 0; i < arrSize; i++) //because i and arrSize are 0 it will not enter the loop so no prob.
        cout << stack[i] << " ";
    cout << endl;
}
int main()
{
    int n, t;
    cin >> n >> t;
    int arr[n];
    while (t--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            push(arr, n);
            print(arr);
        }
        else if (c == 2)
        {
            pop();
            print(arr);
        }
    }
}