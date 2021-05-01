#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

bool comp(std::pair<int,int> &a , std::pair<int,int> &b)
{
    return a.second<b.second; // increasing order 
}

int main()
{
    std::vector<int> yum1 = {1, 2, 5, 8, 9};
    std::vector<int> yum2 = {4, 5, 68, 7, 8};

    std::vector<std::pair<int, int>> pair;

    for (int i = 0; i < 5; i++)
        pair.push_back(std::make_pair(yum1[i], yum2[i]));
    
    std::sort (pair.begin(),pair.end(),comp);
    /*for(auto it :pair ){
        std::cout<< it.first<< " "<<
        it.second<<"\n";
    }*/ //it is not an iterator?
    std::vector<std::pair<int,int>> :: iterator it;

    for(it=pair.begin();it!=pair.end();it++){
        std::cout<<it->first<<" "<<it->second<<"\n";
    } // it is an iterator.
}
