#include<bits/stdc++.h>
using namespace std;

int coins[10]={};
int dp[15][105]={};
int freq[10]={};
int N,W;

void coin_ways()
{
	for(int i=0;i<=W;i++)
	{
		dp[i][0] = 1;
	}

	for(int i=1;i<=W;i++)
	{
		if(i%coins[0] == 0)
			dp[0][i] = 1;
	}

	for(int i = 1; i<= N ;i++)
	{
		for(int j = 1 ; j<= W ;j++)
		{
			if(coins[i]>j)
				dp[i][j] = dp[i-1][j];

			else
				dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];	
		}
	}
}

void input()
{
	cin>>W>>N;

	for(int i = 0 ; i<N ;i++)
		cin>>coins[i];

	sort(coins,coins+4);

}

void print_arr()
{
	for(int i = 0; i< N ;i++)
	{
		for(int j = 0 ; j<= W ;j++)
		{
			cout<<dp[i][j]<<" ";		
		}
		cout<<endl;
	}	
}

void back_track()
{
	int i = N;
	int j = W;

	while(i>=0 && j>=0 && dp[i][j]!=1)
	{
		if(dp[i][j]!=dp[i-1][j])
		{
			cout<<coins[i]<<" ";
			j=j-coins[i];
		}
		else
			i--;
	}
}

int main()
{
	input();
	coin_ways();
	print_arr();
	back_track();
}