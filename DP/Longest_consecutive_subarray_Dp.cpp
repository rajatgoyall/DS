#include<bits/stdc++.h>
using namespace std;

int longest_consecutive_subarray(int *a,int n)
{
	unordered_map<int,bool>m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]=true;
	}
	int ans=0;
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(m.find(a[i]-1)==m.end())
		{
			j=a[i];
			while(m.find(j)!=m.end())
			{
				j++;
			}
			ans=max(ans,j-a[i]);
		}
	}
	return ans;
	
	
}


int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<longest_consecutive_subarray(a,n);

}

