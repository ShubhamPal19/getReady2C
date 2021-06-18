#include <iostream>
using namespace std;




int elephantway(int dp[][100], int x,int y)
{   


    if (x==0&&y==0)
    {
        return dp[x][y]= 1;
    }
    if (dp[x][y]!=-1)
    {
        return dp[x][y];

    }




    int colsum=0,rowsum=0;
    int i,j;
   for ( i = y-1; i >= 0; i--)
        {
            rowsum+=elephantway(dp,x,i);
          
        }

   for ( i =x-1; i >=0; i--)
        {
           colsum+=elephantway(dp,i,y);
        }

    return dp[x][y]=colsum+rowsum;
    
    
    

    
}

int main()
{
    int dp[100][100];
    int i,j,x,y;
    cout <<"Enter the coordinates of destionation : ";

    cin>> x>>y;

    for ( i = 0; i < x+1; i++)
    {
        for ( j = 0; j < y+1; j++)
        {
            dp[i][j]=-1;
        }
        
    }
    
    cout<<"Number of ways to reach at destionation point from origin is "<< elephantway(dp,x,y)<<endl;

    
    for ( i = 0; i < x+1; i++)
    {
        for ( j = 0; j < y+1; j++)
        {
           cout<< dp[i][j]<<"  ";
        }
        cout <<endl;
        
    }


}




// 1       1       2       4       8       16

// 1       2       5       12      28      64

// 2       5       14      37      94      232

// 4       12      37      106     289     760

// 8       28      94      289     838     2329

// 16      64      232     760     2329    6802 
