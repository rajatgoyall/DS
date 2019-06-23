#include<iostream>
#include<string.h>
using namespace std;

class student
{
	char *name;
	int age;
	const int rollnumber;
	static int totalstudents;
	public:
		student(int age,int r, char*name):rollnumber(r)
		{
			this->age=age;
			//this->rollnumber=rollnumber;
			//this->name=name;      shallow copy
			this -> name = new char[strlen(name)+1];
			strcpy(this->name,name);
			totalstudents++;
		}
		
		void print()
		{
			cout<<"Name:" <<name<<endl;
			cout<<"the age is "<<age<<endl;
			cout<<"rollnumber: "<<rollnumber<<endl;
		}
		static int gettotalstudents()
		{
			return totalstudents;
		}
};
int student::totalstudents=0;
