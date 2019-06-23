#include<iostream>
using namespace std;
#include "student.h"

int main()
{
	char name[] ="abcde";
	student s1(20,1001,name);
	s1.print();
	name[2] ='e';
	student s2(21,1002,name);
	s2.print();
	cout<<"the total students present are: "<<student::gettotalstudents<<endl;
	
	
}
