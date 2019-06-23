#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s;
	string A="utkarsh028";
	string B="ars";
//	cout<<A.size();
   // int j=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='a'||A[i]=='b'||A[i]=='c'||A[i]=='d'||A[i]=='e'||A[i]=='f'||A[i]=='g'||A[i]=='h'||A[i]=='i'||A[i]=='j'||A[i]=='k'||A[i]=='l'||A[i]=='m'||A[i]=='n'||A[i]=='o'||A[i]=='p'||A[i]=='q'||A[i]=='r'||A[i]=='s'||A[i]=='t'||A[i]=='u'||A[i]=='v'||A[i]=='w'||A[i]=='x'||A[i]=='y'||A[i]=='z')
        {
        	
            s.push_back(A[i]);
           // cout<<s<<endl;
            continue;
        }
        
        for(int k=0;k<A[i]-48;k++)
        {
            s.push_back('#');
        }
        //cout<<s<<endl;
        
    }
    cout<<s<<endl;
    cout<<B<<endl;
    map<char,int>m1;
    for(int i=0;i<B.size();i++)
    {
        m1[B[i]]++;
    }
    int count=0;
    int temp=0;
    for(int i=0;i<s.size();i++)
    {
        temp=0;
        for(int j=i;j<i+B.size();j++)
        {
            if(s[j]=='#')
            {
                temp++;
                continue;
            }
            if(m1.count(s[j]))
            {
                temp++;
                continue;
            }
            
        }
        cout<<temp<<" ";
        if(temp==B.size())
        count++;
    }
    cout<<endl;
    cout<<count<<endl;
    

}

