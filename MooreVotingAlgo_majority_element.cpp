#include<bits/stdc++.h>
using namespace std;

int getMajorityElement(int arr[],int size)
{
	int majorityindex=0;
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(arr[majorityindex]==arr[i])
		count++;
		else
		count--;
		if(count==0)
		{
			majorityindex=i;
			count=1;
		}
	}
	return arr[majorityindex];
}

int majorityelement(int arr[],int size,int k)
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==k)
		count++;
	}
	return count>(size/2);
}

int main()
{
	int arr[10]={1,2,5,5,8,9,5,8,5,5};
	int a=getMajorityElement(arr,10);
	majorityelement(arr,10,a)?cout<<a<<endl:cout<<"No majority element";
	




}

