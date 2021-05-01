#include <iostream>
#include <cmath>
//
// no clue how it works
// credit 190041117-Reaz
// int func(int n, int k)
// {
//     int a;
//     if (n == 1)
//         return 0;
//     a = func(n - 1, (k + 1) / 2);
//     if (a)
//         return k & 1;
//     else
//         return !(k & 1);
// }

// //
// credit https://www.tutorialspoint.com/k-th-symbol-in-grammar-in-cplusplus
// also check https://leetcode.com/problems/k-th-symbol-in-grammar/
// int kthGrammar(int N, int K)
// {
//     if (N == 1)
//         return 0;
//     if (K % 2 == 0)
//         return kthGrammar(N - 1, K / 2) == 0 ? 1 : 0;
//     else
//         return kthGrammar(N - 1, (K + 1) / 2);
// }

int solve(int n, int k)
{
    if (n == 1)
        return 0;
    int mid = (pow(2, n - 1)) / 2;
    //k <mid ? return solve(n - 1, k) : return !solve(n - 1, k - mid);
    if(k<=mid) return solve(n-1,k);
    else return !solve(n-1,k-mid);
}

// 
// max row= 2^(n-1) 
// k either lies on the first half or the other half
// the halves are compliments of eachother
// if k lies in the first half it returns the same position of its previous row
// else kth position returns the compliment of the previous row
// figure out why we have to return solve(...) and not just solve(...)   ??
//  Ans---> because if we dont return it it will always go to the first if and return a 0. 
// also look https://www.youtube.com/watch?v=5P84A0YCo_Y
//
 

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << solve(n, k);
}