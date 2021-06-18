#include <iostream>
using namespace std;

int elephantway(int X, int Y)
{

    int sum,dp[100][100];
    sum =dp[0][0]=1;
    int i, j, x = 0, y = 0;
    
            cout << dp[0][0] << "  ";

    for (x = 0; x < X + 1; x++)
    {
        for (y = 0; y < Y + 1; y++)
        {
           
            
            for (i = y - 1; i >= 0; i--)
            {
                sum += dp[x][i];
            } 

            for (i = x - 1; i >= 0; i--)
            {
                sum +=dp[i][y];
            }

            dp[x][y]=sum;
           sum=0;
        }
    }

    for (i = 0; i < X + 1; i++)
    {
        for (j = 0; j < Y + 1; j++)
        {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }

    return dp[X][Y] ;
}

int main()
{

    int x, y;
    cout << "Enter the coordinates of destionation : ";

    cin >> x >> y;

    cout << "Number of ways to reach at destionation point from origin is " << elephantway(x, y) << endl;
}


// 1       1       2       4       8       16

// 1       2       5       12      28      64

// 2       5       14      37      94      232

// 4       12      37      106     289     760

// 8       28      94      289     838     2329

// 16      64      232     760     2329    6802 
