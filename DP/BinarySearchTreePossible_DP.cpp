#include<bits/stdc++.h>
using namespace std;

int trees(int n,int *dp)
{
	if(n==1)
	{
		return 1;
	}
	if(dp[n]>-1)
	{
		return dp[n];
	}
	int ans=0;
	for(int k=1;k<=n;k++)
	{
		ans+=trees(k-1,dp)*trees(n-k,dp);
	}
	dp[n]=ans;
	return ans;
}

int it(int n)
{
	int *dp=new int[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<n+1;i++)
	{
		dp[i]=0;
	}
	for(int i=2;i<n+1;i++)
	{
		int ans=0;
		for(int k=1;k<=i;k++)
		{
			ans+=dp[k-1]*dp[i-k];
		}
		dp[i]=ans;
	}
	for(int i=0;i<n+1;i++)
	cout<<dp[i]<<" ";
	cout<<endl;
	int g=dp[n];
	delete []dp;
	return g;
}

int main()
{
	int n;
	cin>>n;
	int* dp=new int[n+1];
	
	for(int i=0;i<n+1;i++)
	dp[i]=-1;
	
	dp[0]=1;
	dp[1]=1;
	
	cout<<it(n);
	delete []dp;
}

