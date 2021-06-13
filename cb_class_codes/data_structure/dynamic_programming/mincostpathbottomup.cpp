

#include <iostream>
using namespace std;




// bottom up

int mincost(int cost[100][100], int n, int s1, int s2, int d1, int d2)
{   

    int dp[100][100],i,j;
    dp[s1][s2]=cost[s1][s2];
    for ( i = s2+1; i < n; i++)
    {
        dp[s1][i]=cost[s1][i]+dp[s1][i-1];

    }
    for ( i = s1+1; i < n; i++)
    {
        dp[i][s2]=cost[i][s2]+dp[i-1][s2];
        
    }
    
    for ( i =s1+1; i < n; i++)
    {
        for ( j = s2+1; j < n; j++)
        {

            dp[i][j]= min(dp[i][j-1],dp[i-1][j])+cost[i][j];  
        }
        
      
    }

    return dp[d1][d2];
    

}

int main()
{
    int cost[100][100];
    int n, i, j;
    cout << "Enter the size of cost matrix : ";
    cin >> n;

    cout << "Enter the matrix" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            
        }
    }
    int s1, s2, d1, d2;
    cout << "Enter the source points : ";
    cin >> s1 >> s2;
    cout << "Enter the destination points : ";
    cin >> d1 >> d2;

    cout << "The minimum cost to get from (" << s1 << "," << s2 << ") to (" << d1 << "," << d2 << ") is " << mincost( cost,n, s1, s2, d1, d2);
}


// 2 1 3 4
// 3 1 1 10
// 1 6 1 1
// 2 7 4 3

// 0 0

// 2 3