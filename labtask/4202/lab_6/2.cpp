#include <iostream>
#include <vector>

int main()
{
    std::vector<int> yum = {1,2,3,4,5,6,7,8,9};

    std::vector<int>::iterator it;
    for (it = yum.begin(); it != yum.end(); it++)
    {
        if(it==yum.begin()+2) yum.erase(it);
        std::cout<< *it<<" ";
    }
}
