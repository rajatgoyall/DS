#include<bits/stdc++.h>
using namespace std;

int getcost(int **input,int m,int n)
{
	int **dp=new int*[m];
	for(int i=0;i<m;i++){
		dp[i]=new int[n];
	}
	
	
	dp[m-1][n-1]=input[m-1][n-1];
	
	for(int i=m-2;i>=0;i--)
	{
		dp[i][n-1]=input[i][n-1]+dp[i+1][n-1];
	}
	
	for(int i=n-2;i>=0;i--)
	{
		dp[m-1][i]=input[m-1][i]+dp[m-1][i+1];
	}
	
	
	
	
	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-2;j>=0;j--)
		{
			dp[i][j]=input[i][j]+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
		}
	}
	/*
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	int ans=dp[0][0];
	
	for(int i=0;i<m;i++)
	{
		delete [] dp[i];

	}
	delete []dp;
	return ans;
}


int main()
{
	int**input=new int*[3];
	for(int i=0;i<3;i++)
	{
		input[i]=new int[3];
	}
	input[0][0]=4;
	input[0][1]=8;
	input[0][2]=1;
	input[1][0]=1;
	input[1][1]=5;
	input[1][2]=9;
	input[2][0]=1;
	input[2][1]=1;
	input[2][2]=8;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		cout<<input[i][j]<<" ";
		cout<<endl;
	}
	int a=getcost(input,3,3);
	cout<<a<<endl;

}

