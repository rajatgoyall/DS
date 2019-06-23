#include<bits/stdc++.h>
using namespace std;

int getmaxzeros(int**input,int m,int n)
{
	int **dp=new int*[m];
	for(int i=0;i<m;i++)
	{
		dp[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		if(input[0][i]==0)
		dp[0][i]=1;
		else
		dp[0][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		if(input[i][0]==0)
		dp[i][0]=1;
		else
		dp[i][0]=0;
	}
	
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int max=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dp[i][j]>max)
			max=dp[i][j];
		}
	}
	for(int i=0;i<m;i++)
	delete []dp[i];
	delete []dp;
	return max;
}


int main()
{
	int**input=new int*[3];
	for(int i=0;i<3;i++)
	{
		input[i]=new int[3];
	}
	input[0][0]=4;
	input[0][1]=0;
	input[0][2]=1;
	input[1][0]=1;
	input[1][1]=0;
	input[1][2]=0;
	input[2][0]=1;
	input[2][1]=0;
	input[2][2]=0;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		cout<<input[i][j]<<" ";
		cout<<endl;
	}
	int a=getmaxzeros(input,3,3);
	cout<<a<<endl;

}

