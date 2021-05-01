#include <iostream>
int fib[40];
int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    if (fib[n] != 0)
    {
        return fib[n];
    }
    else
    {
        fib[n] = fibo(n - 1) + fibo(n - 2) + fibo(n-3);
        return fib[n];
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << fibo(n);
}
