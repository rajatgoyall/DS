#include<iostream>
#include"fraction.h"
using namespace std;
int main()
{
	fraction f1(8,2);
	f1.display();
	fraction f2(5,2);
	
	f2.display();
	fraction f3;
	f3=f1+f2;
	f3.display();
	
	
}
