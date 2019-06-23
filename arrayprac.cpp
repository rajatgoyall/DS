#include<iostream>
using namespace std;
int main()
{
	
	cout<<"Enter the number of rows :"<<endl;
	int m;
	cin>>m;
	cout<<"Enter the number of columns :"<<endl;
	int n;
	cin>>n;
	int a[n][m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"90 degree rotated version:"<<endl;
	for(int i=n-1;i>-1;i--)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[j][i]<<" ";
		}
		cout<<endl;
	}
	cout<<"90 degree rotated version:"<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[m-i-1][n-j-1]<<" ";
		}
		cout<<endl;
	}
}
