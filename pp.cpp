#include <iostream>
#include<stack>

long totalnumbers(int *arr, int n,long long int *fact,int *freq)
{
    
    if(n==1||n==0)
        return 0;
        
    long int count=0;
    long long int den=1;
    for(int i=0;i<10;i++)
    {
        den*=fact[freq[i]];
    }
    for(int i=arr[0]+1;i<10;i++)
    {
        if(freq[i]>0)
        {
            count+=(fact[n-1]/den)*freq[i];
        }
        
    }
    freq[arr[0]]--;
    
    return count+totalnumbers(arr+1,n-1,fact,freq);
    
    
    
    
}

long numberOfNumbersWithDuplicates(long num){
int n=0;
    
    std::stack <int> a;
    while(num!=0)
    {
        a.push(num%10);
        num=num/10;
        
     
     n++;   
        
    }
    int freq[10]={0};
    int s=10>n?10:n;
    long long int *fact=new long long int[s];
    int *arr=new int[n];
    int i=0;
    while(!a.empty())
    {
        arr[i]=a.top();
        a.pop();
        freq[arr[i]]++;
        i++;
            
    }
    fact[0]=1;
    
    for(int j=1;j<s;j++)
    {
        fact[j]=j*fact[j-1];
        
        
    }
    
    long int q=totalnumbers(arr,n,fact,freq);
    delete[]arr;
    delete[]fact;
    return q;

}
using namespace std;

int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
}

