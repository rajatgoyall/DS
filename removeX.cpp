#include<iostream>
using namespace std;

void removeX(char a[],int length)
{
	if(a[0]=='\0')
	{
		return;
	}
	if(a[0]!='x')
	{
		removeX(a+1,length-1);
	}
	int i=1;
	if(a[0]=='x')
	{
		for(;a[i]!='\0';i++)
		{
			a[i-1]=a[i];
		}
		a[i-1]=a[i];
		removeX(a,length-1);
		
	}
}

int getlength(char a[])
{
	int count=0;
	int i=0;
	while(a[i]!='\0')
	{
		count++;
		i++;
	}
	return count;
}

int main()
{
	char c[1000];
	cin>>c;
	int length=getlength(c);
	//cout<<length;
	removeX(c,length);
	cout<<c<<endl;
}
