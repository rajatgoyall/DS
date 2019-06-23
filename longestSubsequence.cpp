#include<bits/stdc++.h>
using namespace std;
vector<int> longestSubsequence(int * arr,int size)
{
	map<int,int> m;
	for(int i=0;i<size;i++)
	{
		m[arr[i]]=i;
	}
	auto it1=m.begin();
	int end=it1->first;
	it1++;
	auto it2=it1;
	it1--;
	int curr_size=1,max_size=1;
	
	while(it2!=m.end())
	{
		int i=it1->first;
		int j=it2->first;
		cout<<i<<" "<<j<<endl;
		if(i+1==j)
			curr_size++;
		else
			curr_size=1;
		if(curr_size>max_size)
		{
			max_size=curr_size;
			end=j;
		}
		else if(curr_size==max_size)
		{
			if(m[end-curr_size+1]>m[j-curr_size+1])
				end=j;
		}
		it1++;
		it2++;
	}
	vector<int> v;
	for(int i=end-max_size+1;i<=end;i++)
		v.push_back(i);
	return v;
}
int main()
{
	int arr[4]={5,3,7,9};
	longestSubsequence(arr,4);
}

