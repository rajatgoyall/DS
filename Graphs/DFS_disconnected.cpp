#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edges,int n,bool* visited,int sv)
{
	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(i!=sv&&edges[i][sv]&&!visited[i])
		{
			printDFS(edges,n,visited,i);
		}
	}
}

void DFS(int **edges,int n)
{
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printDFS(edges,n,visited,i);
		}
	}
	delete []visited;
}

void printBFS(int**edges,int n,int sv,bool* visited)
{
	
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

void BFS(int** edges,int n)
{
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		printBFS(edges,n,i,visited);
	}
	
	delete [] visited;
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
	DFS(edges,n);
	for(int i=0;i<n;i++)
	{
		delete[]edges[i];
	}
	delete[]edges;
}

