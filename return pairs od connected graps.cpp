#include<bits/stdc++.h>
using namespace std;

vector<int> printDFS(int**edges,int n,bool* visited,int sv,vector<int>&a)
{
	visited[sv]=true;
	//cout<<sv<<" ";
	a.push_back(sv);
	for(int i=0;i<n;i++)
	{
		if(i!=sv&&edges[i][sv]&&!visited[i])
		{
			printDFS(edges,n,visited,i,a);
		}
	}
	
	
	return a;
	
}

vector<vector<int>> DFS(int ** edges,int n)
{
	vector<vector<int>>k;
	vector<int>a;
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	printDFS(edges,n,visited,0,a);
	
//	cout<<endl;
	k.push_back(a);
	for(int i=0;i<n;i++)
	{
		a.erase(a.begin(),a.end());
		if(!visited[i])
		{
			
			printDFS(edges,n,visited,i,a);
			k.push_back(a);
		}
	//	cout<<endl;
	}
	return k;
	
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
	vector<vector<int>>l;
	l=DFS(edges,n);
	for(int i=0;i<l.size();i++)
	{
		for(int j=0;j<l[i].size();j++)
		{
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}
	
	

}

