#include<bits/stdc++.h>
using namespace std;

int alpha(int* arr,int n)
{
	int* dp=new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		dp[i]=0;
	}
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<n+1;i++)
	{
		dp[i]=dp[i-1];
		if(arr[i-2]*10+arr[i-1]<=26)
		{
			dp[i]+=dp[i-2];
		}
		
	}
	
	for(int i=0;i<n+1;i++)
	cout<<dp[i]<<" ";
	cout<<endl;
	return dp[n];
	
}


int recursive_alpha(int * a,int n,int * dp)
{
	if(n==1)
	{
		return 1;
	}
	if(dp[n]>-1)
	{
		return dp[n];
	}
	int ans=recursive_alpha(a,n-1,dp);
	if(a[n-2]*10+a[n-1]<=26)
	{
		ans+=recursive_alpha(a,n-2,dp);
	}
	dp[n]=ans;
	for(int i=0;i<5;i++)
	cout<<dp[i]<<" ";
	cout<<endl;
	return ans;
	
}

int main()
{
	int arr[]={1,0.0};
	cout<<alpha(arr,3);
	cout<<endl;
	cout<<"........................";
	int*dp=new int(3);
	for(int i=0;i<3;i++)
	dp[i]=-1;
	dp[0]=1;
	dp[1]=1;
	cout<<recursive_alpha(arr,2,dp);

}

