#include <iostream>

void print(int n){
    if(n<0) return;
    print(n-2);
    std::cout<<n<<" ";
    return;
}

int main(){
    int n;
    std::cin>>n;
    (n&1)==0 ? print(n) : print(n-1); // dont forget the parentheseses aka (n&1).
}