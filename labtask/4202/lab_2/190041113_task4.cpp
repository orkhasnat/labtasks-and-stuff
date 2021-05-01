#include <iostream>
#include <algorithm>

int main()
{
  int n, m;
  std::cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
    arr[i] = 5 - arr[i];
  }
  int team = 0;
  for (int i = 0; i < n; i++)
    if (arr[i] >= m)
      team++;
  std::cout << team / 3;
} 