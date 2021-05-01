#include <iostream>
#include <map>
#include <cstring>

int key[100];
int value[10000];
void print()
{
    for (int i = 0; key[i] != -1; i++)
        std::cout << value[key[i]] << " ";
    std::cout << "\n";
}
void empty()
{
    if (key[0] = -1)
        std::cout << "empty"
                  << "\n";
    else
        std::cout << "not empty"
                  << "\n";
}
void erase(int x)
{
    int i = 0;
    for (; key[i] != -1; i++)
    {
        if (key[i] == x)
            break;
    }
    int size = 0;
    while (key[size] != -1)
        size++;
    for (int j = i; j < size; j++)
        key[j] = key[j + 1];
}
int find(int x)
{
    for (int i = 0; key[i] != -1; i++)
    {
        if (key[i] == x)
            return i;
    }
    return -1;
}

void insert(int k, int val)
{
    int in = find(k);
    if (in >= 0)
        value[key[in]] = val;
    else
    {
        int i=0;
        while(key[i]!=-1) i++;
        key[i] = k;
        value[key[i]] = val;
    }
}
int main()
{
    std::map<int, int> yum;
    std::cout << yum.empty() << "\n";
    yum.insert(std::pair<int, int>(1, 250));
    yum.insert(std::pair<int, int>(2, 345));
    yum.insert(std::pair<int, int>(3, 34));
    yum.insert(std::pair<int, int>(4, 3405));
    yum.erase(2);
    std::map<int, int>::iterator it = yum.find(1);
    while (it != yum.end())
    {
        std::cout << it->second << " ";
        it++;
    }
    std::cout << "\nThis part is for arrays!!\n";
    memset(key, -1, sizeof(key));
    insert(2, 378);
    insert(1, 509);
    insert(5, 81);
    print();
    std::cout << find(2) << "\n";
    erase(2);
    std::cout << find(2) << "\n";
    print();
}
