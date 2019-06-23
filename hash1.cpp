#include<iostream>
#include<unordered_map>
using namespace std;

void intersection(int input1[],int input2[],int size1,int size2)
{
	unordered_map<int,int>ourmap1;
	unordered_map<int,int>ourmap2;
	
	for(int i=0;i<size1;i++)
	{
		ourmap1[input1[i]]++;
	}
	for(int i=0;i<size2;i++)
	{
		ourmap2[input2[i]]++;
	}
	for(auto it=ourmap1.begin();it != ourmap1.end();it++)
	{
		int t=min(it->second,ourmap2[it->first]);
		for(int i=0;i<t;i++)
		{
			cout<<it->first<<endl;
		}
	}
}


int main()
{
	int a[9]={1,2,2,4,5,6,7,8,9};
	int b[6]={1,2,2,2,5,6};
	
	intersection(a,b,9,6);
	
	
}
