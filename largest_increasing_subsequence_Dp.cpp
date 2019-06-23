#include<bits/stdc++.h>
using namespace std;

int longest_increasing_sub_sequence(int* a,int n)
{
	int b[n];
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	//b[0]=a[0];
	for(int i=0;i<n;i++)
	{
		for(int j=i-1;j>-1;j--)
		{
			if(a[i]>a[j]&&b[j]>=0)
			{
				if(b[i]<b[j]+a[i])
				b[i]=b[j]+a[i];
			}
		}
	}
	int max=b[0];
	for(int i=1;i<n;i++)
	{
		if(max<b[i])
		max=b[i];
	}
	cout<<max<<endl;
	
}

int main()
{
	int a[]={1,5,6,-3,2,-12,8,9,5,-20};
	longest_increasing_sub_sequence(a,10);

}

