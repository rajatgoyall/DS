#include<iostream>
using namespace std;

template<typename V>
class Quees{
	int firstindex=-1;
	int nextindex=0;
	V* data;
	int capacity=5;
	int size=0;
	
	public:
		Quees(int cap)
	{
		int firstindex=-1;
		int nextindex=0;
		capacity=cap;
		data=new V[capacity];
	}
	
	bool isEmpty()
	{
		return size==0;
	}
	
	V front()
	{
		return data[frontindex];
	}
	
	void enquee(V value)
	{
		if(nextindex==firstindex)
		{
			cout<<"quee is full"<<endl;
			return;
		}
		if(firstindex==-1)
		{
			firstindex=0;
		}
		
		
		data[nextindex]=value;
		nextindex=(nextindex+1)%capacity;
		size++;
		return;
	}
	
	V dequee()
	{
		
		int output=data[firstindex];
		firstindex=(firstindex+1)%capacity;
		if(isEmpty())
		{
			firstindex=-1;
			nextindex=0;
		}
		return output;
	}
	void print()
	{
		int index=firstindex;
		for(int i=0;i<capacity;i++)
		{
			cout<<data[i]<<" ";
			index++;
		}
	}
	
	
	
};

int main()
{
	Quees <int>q(5);
	q.enquee(10);
	q.enquee(20);
	q.enquee(30);
	q.enquee(40);
	q.enquee(50);
	q.dequee();
	q.enquee(80);
	q.print();
	cout<<endl;
	
}
