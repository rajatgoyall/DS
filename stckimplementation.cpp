#include<iostream>
using namespace std;


class stack{
	int *data;
	int capacity=0;
	int nextindex=0;
	public:
	stack()
	{
		capacity=4;
		data=new int[capacity];
	}
	
	void push(int value)
	{
		if(nextindex==capacity)
		{
			int oldcapacity=capacity;
			capacity*=2;
			int * newdata=new int[capacity];
			for(int i=0;i<nextindex;i++)
			{
				newdata[i]=data[i];
			}
			delete []data;
			data=newdata;
		}
		data[nextindex]=value;
		nextindex++;
	}
	
	int pop()
	{
		int rv=data[nextindex-1];
		nextindex--;
		return rv;
	}
	
	void print()
	{
		for(int i=0;i<nextindex;i++)
		{
			cout<<data[i]<<" ";
		}
	}
	
	
	
};

int main()
{
	stack s;
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.print();
	
	
	
}
