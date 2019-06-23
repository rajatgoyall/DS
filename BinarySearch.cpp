#include<bits/stdc++.h>
using namespace std;

bool BinarySearch(int*arr,int n,int k)
{
	int a=0,b=n-1,m;
	m=(a+b)/2;
	if(k>arr[b]||k<arr[a])
	return false;
	while(a<b)
	{
		if(arr[m]==k)
		{
			return true;
		}
		if(arr[m]>k)
		{
			b=m;
			m=(a+b)/2;
			continue;
		}
		if(arr[m]<k)
		{
			a=m;
			m=(a+b)/2;
			continue;
		}
	}
	return false;
	
	
}

int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	BinarySearch(arr,10,1)?cout<<"Found:)":cout<<"Not Found";

}

