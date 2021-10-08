#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using std::cin, std::cout, std::endl;

int main()
{
    int arr[5];
    std::set<int> s;
    for (int i = 0, j = 0; i < 10; i++)
    {
        // i&1  ? s.insert(i) : arr[j++] = i;
        if (i & 1)
            s.insert(i);
        else
            arr[j++] = i;
    }
    std::vector<int> vec(10);
    std::merge(arr, arr + 5, s.begin(), s.end(), vec.begin());
    for (auto it : vec)
        cout << it << " ";
    cout << "\b\n";
}