#include <iostream>
#include <algorithm>

void bubblesort(int n, int arr[])
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
        std::swap(arr[j], arr[j + 1]);
    }
  }
} 

int maxSum(int n,int m,int arr[]){
  int sum=0;
  for (int i = m; i < n; i++)
  {
    sum+=arr[i];
  }
  
  return sum;
}

int minSum(int n,int m,int arr[]){
  int sum=0;
  for (int i = 0; i < n-m; i++)
  {
    sum+=arr[i];
  }
  
  return sum;
}

int main()
{
  int t;
  std::cin>>t;
  while(t--)
  {
    int n, m;
    std::cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
      std::cin >> arr[i];
    bubblesort(n, arr);
    int result = maxSum(n,m,arr)-minSum(n,m,arr);
    std::cout<<result<<std::endl;
    // for (int i = 0; i < n; i++)
    //   std::cout << arr[i] << " ";
  }
}