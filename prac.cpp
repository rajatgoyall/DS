#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

vector<int> removeduplicates(int* a,int n)
{
	vector<int>output;
	unordered_map<int,bool>ourmap;
	for(int i=0;i<n;i++)
	{
		if(ourmap.count(a[i])>0)
		{
			continue;
		}
		output.push_back(a[i]);
		ourmap[a[i]]=true;
	}
	return output;
	
}

int main()
{
	int a[]={1,3,3,3,3};
	vector <int>  c=removeduplicates(a,5);
	for(int i=0;i<c.size();i++)
	{
		cout<<c[i]<<endl;
	}
}
