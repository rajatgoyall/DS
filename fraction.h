#include<iostream>
using namespace std;


class fraction{
	int numerator;
	int denominator;
	
	public:
		 fraction()
		{
			this->numerator=0;
			this->denominator=1;	
		}
		
		  fraction(int n,int d)
		{
			this->numerator=n;
			this->denominator=d;	
		}
		
		void display()
		{
			this->simplify();
			if(denominator==1)
			{
				cout<< numerator <<endl;
				return;
			}
			cout<<this->numerator<<"/"<<this->denominator<<endl;
		//	return;
		}
		
		void simplify()
		{
			int n=this->numerator>this->denominator?denominator:numerator; 
			int hcf=1;
			for(int i=1;i<=n;i++)
			{
				if(numerator%i==0&&denominator%i==0)
				{
					hcf=i;
				}
				
			}
			numerator=numerator/hcf;
			denominator=denominator/hcf;
		}
		void add(fraction const & f2)
		{
			int lcm=denominator*f2.denominator;
			int x=lcm/denominator;
			int y=lcm/f2.denominator;
			
			int num=numerator*x+(y*f2.numerator);
			numerator=num;
			denominator=lcm;
			this->simplify();
		}
		
		fraction operator+(fraction const & f2)
		{
			fraction fnew ;
			int lcm=denominator*f2.denominator;
			int x=lcm/denominator;
			int y=lcm/f2.denominator;
			
			int num=numerator*x+(y*f2.numerator);
			fnew.numerator=num;
			fnew.denominator=lcm;
			fnew.simplify();
			this->simplify();
			return fnew;
			
		}
		
};
