#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	unordered_map<int,bool>ourmap;
	vector<int>a;
	int input;
	cin>>input;
	while(input!=-1)
	{
		if(!ourmap[input])
		{
			a.push_back(input);
			ourmap[input]=true;
		}
		cin>>input;
		
		
	}
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<endl;
	}
	
}
