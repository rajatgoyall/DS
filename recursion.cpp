#include<iostream>
#include<string>

using namespace std;

int f(int number,string output[])
{
	if(number==1||number==2||number==3)
	{
		if(number==1)
		{
			output[0]="a";
			output[1]="b";
			output[2]="c";
			
		}
		if(number==2)
		{
			output[0]="d";
			output[1]="e";
			output[2]="f";
			
		}
		if(number==3)
		{
			output[0]="g";
			output[1]="h";
			output[2]="i";
			
		}
		return 3;
		
	}
	int smallnumber=number%10;
	int remainingnumber=number/10;
	int count=f(remainingnumber,output);
	//cout<<count<<endl;
	string *o2=new string[1000];
	for(int i=0;i<count;i++)
	{
		o2[i]=output[i];
		
	}
	for(int i=0;i<count;i++)
	{
		if(smallnumber==1)
		{
			output[i]=o2[i]+"a";
			
		}
		if(smallnumber==2)
		{
			output[i]=o2[i]+"d";
			
		}
	
	    if(smallnumber==3)
		{
			output[i]=o2[i]+"g";
			
		}
	}	
	for(int i=0;i<count;i++)
    {
	   	
		if(smallnumber==1)
		{
			output[i+1*count]=o2[i]+"b";
			
		}
		if(smallnumber==2)
		{
			output[i+1*count]=o2[i]+"e";
			
		}
	
	   if(smallnumber==3)
		{
			output[i+1*count]=o2[i]+"h";
			
		}
	}
		for(int i=0;i<count;i++)
	{
		if(smallnumber==1)
		{
			output[i+2*count]=o2[i]+"c";
			
		}
		if(smallnumber==2)
		{
			output[i+2*count]=o2[i]+"f";
			
		}
	
	    if(smallnumber==3)
		{
			output[i+2*count]=o2[i]+"i";
			
		}
	}
	
	
	
		
	
	return 3*count;
}

int main()
{
	int input;
	cin>>input;
	string* output=new string[1000];
	int c=f(input,output);
	for(int i=0;i<c;i++)
	{
		cout<<output[i]<<endl;
	}
}
