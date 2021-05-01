#include <iostream>
#include <cmath>

int solve(int n, int k)
{
    if (n == 1)
        return 0;
    int mid = (pow(2, n - 1)) / 2;
    //k <mid ? return solve(n - 1, k) : return !solve(n - 1, k - mid); // problem??
    if(k<=mid) return solve(n-1,k);
    else return !solve(n-1,k-mid);
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << solve(n, k);
}