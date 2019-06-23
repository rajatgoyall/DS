#include<iostream>
using namespace std;

void removeduplicates(char a[],int length)
{
	if(length==0)
	{
		return;
	}
	if(a[0]!=a[1])
	{
		removeduplicates(a+1,length-1);
		return;
	}
	int i=1;
	if(a[0]==a[1])
	{
		for(;a[i]!='\0';i++)
		{
			a[i-1]=a[i];
		}
		a[i-1]=a[i];
		removeduplicates(a,length-1);
		
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
	char c[100];
	cin>>c;
	int length=getlength(c);
	//cout<<length;
	removeduplicates(c,length);
	cout<<c<<endl;
}
