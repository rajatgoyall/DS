#include<bits/stdc++.h>
using namespace std;

vector<int> getpath(int**edges,int n,int sv,int ev,bool* visited,vector<int>a)
{
	visited[sv]=true;
	if(sv==ev)
	{
	//	vector<int>a;
		a.push_back(sv);
		return a;
		
	}
	
	for(int i=0;i<n;i++)
	{
		if(i==sv)
		{
			continue;
		}
		if(edges[i][sv]==1&&!visited[i])
		{
			a=getpath(edges,n,i,ev,visited,a);	
			if(a.size())
			{
				
				a.push_back(sv);
				return a;
			}
		}
		//cout<<i<<endl;
	}
//	cout<<"at the end"<<endl;
//	vector <int> a;
	return a;
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
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	vector<int>path;
	vector<int>output=getpath(edges,n,0,2,visited,path);
	cout<<"................................"<<endl;
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i]<" ";
	}

}

