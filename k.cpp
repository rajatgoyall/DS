#include<iostream>
using namespace std;
#include<unordered_map>
bool sudokuSolver(int board[][9],int x=0,int y=0){ 
    if(x==9)
    {
        return true;
    }
    if(board[x][y]!=0)
    {     
        if(y==8)
        {
            x++;
            y=0;
        }
        else
            y++;
       return sudokuSolver(board,x,y);
    }
    unordered_map<int,bool>a;
    for(int i=1;i<=9;i++)
        a[i]=true;
    for(int i=0;i<9;i++)
    {   
        a[board[x][i]]=false;
    }
    for(int i=0;i<9;i++)
    {
        
        a[board[i][y]]=false;
    }
    int c1=y/3;
    c1=3*c1;
    int r1=x/3;
    r1=3*r1;
    for(int i=r1;i<r1+3;i++)
    {
        for(int j=c1;j<c1+3;j++)
        {
            a[board[i][j]]=false;   
        }
    }
    for(int i=1;i<=9;i++)
    {
        if(a[i])
        {
            board[x][y]=i;
            if(y==8)
            {
                x++;
                y=0;    
            }
            else
            {
                y++;
            }
            
            if(sudokuSolver(board,x,y))
                return true;  
            board[x][y]=0;
        } 
         
    }
    
    return false;
}
int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
for(int j = 0; j < n; j++){
        cin >> board[i][j];
        }	
  }
  if(sudokuSolver(board)){
cout << "true";	
  }else{
cout << "false";	
  }
}
