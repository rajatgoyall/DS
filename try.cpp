#include<bits/stdc++.h>
using namespace std;
int b(int &g)
{
	static int a=g;
	a+=1;
//	cout<<a;
	return a;
}
int main()
{
	int g=0;
	int a=b(g);
	cout<<a<<endl;
	g=10;
	a=b(g);
	cout<<a;
}
