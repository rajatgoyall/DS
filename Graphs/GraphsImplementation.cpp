#include<bits/stdc++.h>
using namespace std;

void printDFS(int**edges,int n,int sv)
{
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	
	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(i==sv)
		{
			continue;
		}
		
		if(edges[sv][i]==1)
		{
			if(visited[i]==1)
			{
				continue;
			}
			printDFS(edges,n,i);
		}
	}
	
}

void printBFS(int**edges,int n,int sv)
{
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	queue<int>pendingvertices;
	pendingvertices.push(sv);
	visited[sv]=true;
	while(!pendingvertices.empty())
	{
		int current_vertex=pendingvertices.front();
		pendingvertices.pop();
		cout<<current_vertex<<endl;
		for(int i=0;i<n;i++)
		{
			if(edges[i][current_vertex]==1&&i!=current_vertex&&!visited[i])
			{
				pendingvertices.push(i);
				visited[i]=true;
			}
		}
	}
}


int main()
{
	int n,e;
	cin>>n>>e;
	int **edges=new int*[n];
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
	printBFS(edges,n,0);

}

