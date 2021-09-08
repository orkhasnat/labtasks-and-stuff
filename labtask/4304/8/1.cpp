#include "Trie.cpp"

int main()
{
    int n, q;
    std::string a;
    Trie dict;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        dict.insert(a);
        a.std::string::~string();
    }
    dict.display(',');
    for (int i = 0; i < q; i++)
    {
        std::cin >> a;
        std::cout<<dict.commonPrefixWordCount(a)<<std::endl;
        a.std::string::~string();
    }
}

// Beauty
// Beast
// Beautiful
// Amazing
// Amsterdam
// Beautify
// Banana
// Xray
// Beauty
// Glorifying
// A
// Am
// AM
// Beauty
// Beaut
// Beast
// Ing
// AMS
// Be
// B

// 2
// 2
// 2
// 2
// 4
// 1
// 0
// 1
// 5
// 6
