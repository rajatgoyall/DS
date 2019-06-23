#include<bits/stdc++.h>
using namespace std;

int max_sum(int *a,int n)
{
	int b[n];
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		if(b[i-1]<0)
		{
			b[i]=a[i];
			continue;
		}
		b[i]=b[i-1]+a[i];
	}
	int max=b[0];
	for(int i=0;i<n;i++)
	{
		if(max<b[i])
		max=b[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	return max;
}

int main()
{
	int a[]={-4,5,6,2,-6,7,8,9,0,4};
	cout<<endl;
	cout<<max_sum(a,10);

}

