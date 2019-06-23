#include<bits/stdc++.h>
using namespace std;
int steps(int n,int dp[])
{
	if(n==1)
	{
		dp[1]=0;
		return 0;
	}
	if(dp[n]>-1)
	{
		return dp[n];
	}
	
	int k=n;
	if(n%3==0)
	{
		n=n/3;
	}else if(n%2==0)
	{
		n=n/2;
	}else
	{
		n=n-1;
	}
	
	//cout<<n;
	int ans=1+steps(n,dp);
	dp[k]=ans;
	cout<<ans<<endl;
	return ans;
	
}

int steps2(int n)
{
	int dp2[n+1]={-1};
	dp2[1]=0;
	for(int i=2;i<n+1;i++)
	{
		if(i%3==0)
		{
			dp2[i]=1+dp2[i/3];
		}else if(i%2==0)
		{
			dp2[i]=1+dp2[i/2];
		}else{
			dp2[i]=1+dp2[i-1];
		}
	}
	
	for(int i=0;i<n+1;i++)
	{
		cout<<dp2[i]<<" ";
	}
	return dp2[n];
}

int main()
{
	int* dp=new int[10];
	for(int i=0;i<10;i++)
	{
		dp[i]=-1;
	}
	
	cout<<steps2(7)<<endl;
	
}

