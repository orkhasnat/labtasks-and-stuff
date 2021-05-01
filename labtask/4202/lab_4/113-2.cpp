#include <iostream>
#define RT 1

#if RT == 1
#include <string>

std::string superdigit(std::string n){
    int out=0;
    if(n.size()==1) return n;
    for(auto i : n)
        out += (i-'0');
    return superdigit(std::to_string(out));
}

int main(){
    std::string n;
    int k;
    std::cin>>n>>k;
    n=superdigit(n); // unichar string
    k=(n[0] - '0') * k;
    std::cout<<superdigit(std::to_string(k));
}

//=================================================================
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
int superdigit(int n)
{
    if (n < 10)
        return n;
    int out = n % 10;
    out += superdigit(n / 10);
    superdigit(out);
}
#pragma GCC diagnostic pop
int main()
{
    int n, k;
    std::cin >> n >> k;
    n = superdigit(n);
    n = superdigit(n * k);
    std::cout << n;
}
#endif