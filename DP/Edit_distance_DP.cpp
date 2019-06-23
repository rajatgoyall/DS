#include<bits/stdc++.h>
using namespace std;




int editdistance(char*a,char*b)
{
	int m=strlen(a);
	int n=strlen(b);
	int**dp=new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i]=new int[n+1];
	}
	for(int i=0;i<=m;i++)
	{
		dp[i][0]=i;
	}
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=i;
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
			}
		}
	}
	/*
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	int ans=dp[m][n];
	
	for(int i=0;i<=m;i++)
	{
		delete [] dp[i];
	}
	delete [] dp;
	
	return ans;
}


int editdistancehelper(char*a,char*b,int m,int n,int**dp)
{
	int ans;
	if(dp[m][n]>-1)
	{
		return dp[m][n];
	}
	if(a[0]==b[0])
	{
		ans=editdistancehelper(a+1,b+1,m-1,n-1,dp);
	}else
	{
		ans=1+min(editdistancehelper(a+1,b+1,m-1,n-1,dp),
					min(editdistancehelper(a+1,b,m-1,n,dp),
					editdistancehelper(a+1,b+1,m-1,n-1,dp)));
		
	}
	dp[m][n]=ans;
	return ans;
	
	
}

int geteditdistance(char*a,char*b)
{
	int m=strlen(a);
	int n=strlen(b);
	
	int **dp=new int*[m+1];
	for(int i=0;i<=m;i++)
	dp[i]=new int[n+1];
	
	for(int i=0;i<=m;i++)
	dp[i][0]=i;
	for(int i=0;i<=n;i++)
	dp[0][i]=i;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		dp[i][j]=-1;
	}
	
	int ans=editdistancehelper(a,b,m,n,dp);
	for(int i=0;i<=m;i++)
	{
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}



int main()
{
	char a[100];
	char b[100];
	cin>>a;
	cin>>b;
	cout<<geteditdistance(a,b)<<endl;
	cout<<editdistance(a,b);
}

