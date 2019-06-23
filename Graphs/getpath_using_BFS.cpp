#include<bits/stdc++.h>
using namespace std;

void getpath(int** edges,int n,int si,int ei)
{
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	queue<int>pendingvertices;
	map<int,int>m;
	pendingvertices.push(si);
	while(pendingvertices.size())
	{
		
		//4 3 0 1 1 2 2 3 
		int currentvertex=pendingvertices.front();
	//	cout<<"i am in"<<currentvertex<<endl;
		pendingvertices.pop();
		for(int i=0;i<n;i++)
		{
			if(i==si)
			continue;
			if(edges[i][currentvertex]==1&&!visited[i])
			{
			//	cout<<i<<endl;
				pendingvertices.push(i);
				visited[i]=true;
				m[i]=currentvertex;
			//	cout<<"............"<<pendingvertices.size()<<endl;
			}
		}
		
	}
	int key;
	int value=ei;
	vector<int>a;
	a.push_back(ei);
	/*
	for(auto it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<" -> "<<it->second<<endl;
	}*/
	
	for(int i=0;i<m.size();i++)
	{
		
		for(auto it=m.begin();it!=m.end();it++)
		{
			if(it->first==value)
			{
				a.push_back(it->second);
				value=it->second;
				if(it->second==si)
				{
					break;
				}
			}
		}
	}
	//a.push_back(value);
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}

	
}

int main()
{
	int n,e;
	cin>>n>>e;
	int**edges=new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	getpath(edges,n,0,7);

}

