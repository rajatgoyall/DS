#include<bits/stdc++.h>
using namespace std;


int findindex(int*arr,int n,int k)
{
	if(!n)
	{
		return 0;
	}
	if(arr[0]!=k)
	{
		int a=findindex(arr+1,n-1,k);
		if(a)
		return a;
		return 0;
	}
	if(arr[0]==k)
	{
		int a=findindex(arr+1,n-1,k);
		if(a)
		return a;
		return n;;
	}
}

int lastIndex(int input[], int size, int x, int currIndex){
    if(currIndex== size){
        return -1;
    }

    int index = lastIndex(input,size,x,currIndex+1);
    
    if(index == -1 && input[currIndex] == x){
        return currIndex;
    }
    else{
        return index;
    }
}


int fi(int*arr,int n,int k)
{
	return findindex(arr, n, k,0);
}




int main()
{
	int arr[10]={9,2,3,4,5,1,2,1,1,8};
	int p=fi(arr,10,8);
	cout<<p<<endl;
}

