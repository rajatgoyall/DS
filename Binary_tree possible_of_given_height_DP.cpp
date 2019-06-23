#include<bits/stdc++.h>
using namespace std;

int number_of_trees_iterative(int h)
{
	int* dp=new int[h+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<h+1;i++)
	{
		dp[i]=dp[i-1]*dp[i-1]+2*dp[i-1]*dp[i-2];
	}
	for(int i=0;i<h+1;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[h];
	
	
}

int number(int n,int *dp)
{
	if(n==0||n==1)
	{
		return 1;
	}
	if(dp[n])
	{
		return dp[n];
	}
	
	int ans=number(n-1,dp)*number(n-1,dp)+2*number(n-1,dp)*number(n-2,dp);
	dp[n]=ans;
	return ans;
	
}

int main()
{
	int *dp=new int[4];
	for(int i=0;i<4;i++)
	{
		dp[i]=0;
	}
	dp[0]=1;
	dp[1]=1;
	cout<<number(3,dp);

}

