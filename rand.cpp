#include<iostream>
using namespace std;
void printpossible(int **arr,int n,int **sol,int x,int y)
{

    if(x==n-1&&y==n-1)
    {
        sol[x][y]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        sol[x][y]=0;
        cout<<endl;
        return;

    }
    if(x<0||y<0||x>=n||y>=n||arr[x][y]==0||sol[x][y]==1)
    return ;
    sol[x][y]=1;
    printpossible(arr,n,sol,x-1,y);
    printpossible(arr,n,sol,x+1,y);
    printpossible(arr,n,sol,x,y-1);
    printpossible(arr,n,sol,x,y+1);
    sol[x][y]=0;
    return;

}
bool helppossible(int **arr,int n,int **sol,int x,int y)
{
    if(x==n-1&&y==n-1)
    return true;
    if(x<0||y<0||x>=n||y>=n||arr[x][y]==0||sol[x][y]==1)
    return false;
    sol[x][y]=1;
    if(helppossible(arr,n,sol,x-1,y))
    return true;
    if(helppossible(arr,n,sol,x+1,y))
    return true;
    if(helppossible(arr,n,sol,x,y-1))
    return true;
    if(helppossible(arr,n,sol,x,y+1))
    return true;
    sol[x][y]=0;
    return false;



}
void ispossible(int **arr,int n)
{
     int **sol=new int*[n];
    for(int i=0;i<n;i++)
    {
        sol[i]=new int [n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sol[i][j]=0;
        }
    }
    printpossible(arr,n,sol,0,0);

}

int main()
{
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int [n];
    }

    for(int i=0;i<n;i++ )
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    ispossible(arr,n);


}
