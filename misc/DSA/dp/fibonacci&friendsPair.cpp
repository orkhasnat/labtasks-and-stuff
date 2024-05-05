#include<bits/stdc++.h>
using namespace std;

int friends[100]={}, N;
int fibo[100]={};

void print_arr(int N, int arr[])
{
	cout<<endl;
	for(int i=0 ; i<=N ;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void friends_pair(int N)
{
	for(int i = 0; i<= N ; i++)
	{
		if(i<3)
			friends[i] = i;
		else
			friends[i] = friends[i-1] + (i-1)*friends[i-2] ;
	}
}

void fib(int N)
{
	for(int i = 0; i<= N ; i++)
	{
		if(i<2)
			fibo[i] = i;
		else
			fibo[i] = fibo[i-1] + fibo[i-2] ;
	}
}

int main()
{
	cin>>N;
	//friends_pair(N);
	fib(N);
	print_arr(N, fibo);
}