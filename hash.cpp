#include<bits/stdc++.h>

using namespace std;

void intersection(int input1[],int input2[],int size1,int size2)
{
	unordered_map<int,int>ourmap;
	for(int i=0;i<size1;i++)
	{
		if(ourmap.count(input1[i])==0)
		{
		
	    	pair<int,int>p;
		    p.first=input1[i];
		     p.second=1;
		     ourmap.insert(p);
	   }
	   else
	   {
	     	ourmap[input1[i]]++;
	   }
	}
	for(int i=0;i<size2;i++)
	{
		if(ourmap.count(input2[i]))
		{
			if(ourmap[input2[i]]==1)
			{
				cout<<input2[i]<<endl;
				ourmap.erase(input2[i]);
			}
			cout<<input2[i]<<endl;
			ourmap[input2[i]]--;
			
		}
		
	}
}


int main()
{
	
	
}
