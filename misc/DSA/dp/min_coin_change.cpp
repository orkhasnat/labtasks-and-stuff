#include<bits/stdc++.h>
using namespace std;

int coins[100]={};
int dp[10][105]={};
int N,W;

void input()
{
	cin>>W>>N;

	for(int i=1;i<=N;i++)
	{
		cin>>coins[i];
	}
}


void print_ar()
{
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=W;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

void min_coins()
{
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(j==0)
				dp[i][j] = 0;
			else
				dp[i][j] = 100000;
		}
	}


	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(coins[i]>j)
				dp[i][j] = dp[i-1][j];

			else
				dp[i][j] = min (dp[i-1][j], 1 + dp[i][j-coins[i]]);
		}
	}
}

int main()
{
	input();	
	min_coins();
	print_ar();
}