#include<bits/stdc++.h>
using namespace std;

bool haspath(int **edges,int n,int sv,bool* visited,int k)
{
	
	visited[sv]=true;
	if(sv==k)
	{
		return true;
	}
	if(edges[sv][k]==1)
	{
		return true;
	}
	for(int i=0;i<n;i++)
	{
		if(i==sv)
		continue;
		if(edges[i][sv]==1&&!visited[i])
		{
			return haspath(edges,n,i,visited,k);
		}
	}
	return false;
	
	
}

bool hp(int**edges,int n,int sv,int k)
{
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	return haspath(edges,n,sv,visited,k);
	
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
	hp(edges,n,0,2)?cout<<"it has :) ":cout<<"it does not :( ";


}

