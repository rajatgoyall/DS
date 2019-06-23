#include<bits/stdc++.h>
using namespace std;

bool findpair(int arr[],int n)
{
	unordered_map<int,pair<int,int> >m;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int sum=arr[i]+arr[j];
			if(m.find(sum)!=m.end())
			{
				pair<int,int> temp=m[sum];
				if(temp.first!=arr)
			}
			else
				m[sum]=make_pair(arr[i],arr[j]);
		}
	
	
	return false;
}

int main()
{
	int a[5]={1,2,6,8,55};
	cout<<findpair(a,5)<<endl;

}

