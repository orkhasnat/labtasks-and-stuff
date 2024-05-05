#include<bits/stdc++.h>
using namespace std;

int weights[100]={}, prices[100]={},dp[100][100]={};
int N,W;

int input()
{
	cin>>W>>N;

	for(int i=1;i<=N;i++)
		cin>>weights[i];

	for(int i=1;i<=N;i++)
		cin>>prices[i];
}

void knapsack()
{
	for(int i=0;i<=W;i++)
		dp[0][i] = 0;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(weights[i]>j)
				dp[i][j] = dp[i-1][j];

			else
				dp[i][j] = max(dp[i-1][j],prices[i]+dp[i-1][j-weights[i]]);
		}
	}
}

void print_arr()
{
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=W;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{

	input();
	knapsack();

	print_arr();
}