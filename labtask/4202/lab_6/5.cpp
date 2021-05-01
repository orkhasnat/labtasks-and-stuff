#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>

int a[100];

void print()
{
    for (int i = 0; a[i] != -1; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
}

int count(int x)
{
    for (int i = 0; a[i] != -1; i++)
    {
        if (a[i] == x)
            return 1;
    }
    return 0;
}
void insert(int x)
{
    if (count(x))
        return;
    int i=0;
    while (a[i]!=-1)
        i++; //traversal       
    a[i]=x;
    std::sort(a, a + i);

}
int main()
{
    std::set<int> yum;
    std::set<int>::iterator it;
    yum.insert(2);
    yum.insert(4);
    yum.insert(5);
    yum.insert(6);
    for (it = yum.begin(); it != yum.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout<<yum.count(5)<<" , "<<yum.count(3);
    std::cout << "\nThis part is for arrays!!\n";
    memset(a, -1, sizeof(a));
    insert(2);
    insert(2);
    insert(10);
    insert(12);
    insert(14);
    print();
    std::cout << count(2)<<" , "<<count(11) << "\n";
}