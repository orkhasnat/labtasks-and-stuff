#include<bits/stdc++.h>
using namespace std;

int prices[10]={};
int dp[15][15]={};
int freq[10]={};
int N;

void print_arr()
{
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*void rod_cutting()
{
	for(int i=0;i<=N;i++)
		dp[0][i] = 0;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			
			if(i>j)
				{
					dp[i][j] = dp[i-1][j];
					cout<<dp[i-1][j]<<" ";
				}
			
			else
			{
				cout<<"( "<<dp[i-1][j]<<" , "<<prices[i]<<" + "<<dp[i][j-i]<<")"<<"  ";
				dp[i][j] = max(dp[i-1][j], prices[i] + dp[i][j-i]);
			}
		}
		cout<<endl;
	}
}*/

void rod_cutting()
{
	for(int i=0;i<=N;i++)
		dp[0][i] = 0;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(i>j)
				dp[i][j] = dp[i-1][j];

			else
				dp[i][j] = max(dp[i-1][j], prices[i] + dp[i][j-i]);
		}	
	}
}

void input(int N)
{
	for(int i=1;i<=N;i++)
		cin>>prices[i];
}

void back_track()
{
	int i = N;
	int j = N;
	while(dp[i][j]!=0 && j !=0 && i !=0)
	{
		if(dp[i][j] == dp[i-1][j])
			i--;
		else
		{
			cout<<i<<" ";
			j = j-i;
		}
	}
}

int main()
{
	cin>>N;
	input(N);
	rod_cutting();

	/*for(int i = 0; i<= N ; i++)
		cout<<prices[i]<<" ";
	cout<<endl;
*/
	print_arr();

	back_track();
}