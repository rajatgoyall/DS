#include<bits/stdc++.h>
using namespace std;

int f(int n,char prev,char prevprev)
{
	if(n==1)
	{
		return 1;
	}
	
	if(prev=='B'&&prevprev=='W')
	{
		return f(n-1,'R','B');
	}
	if(prev=='B'&&prevprev=='R')
	{
		return f(n-1,'W','B');
	}
	if(prev='W')
	{
		return f(n-1,'B','W')+f(n-1,'R','W');
	}
	if(prev='R')
	{
		return f(n-1,'B','R')+f(n-1,'W','R');
	}
	
	
}

int g(int n)
{
	return f(n,'B','W')+f(n,'B','R');
}



int main()
{
	int k;
	cin>>k;
	cout<<g(k)<<endl;
}

