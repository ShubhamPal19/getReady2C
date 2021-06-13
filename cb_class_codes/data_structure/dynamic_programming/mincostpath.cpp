

#include <iostream>
using namespace std;

int mincost(int dp[100][100], int cost[100][100],  int s1, int s2, int d1, int d2)
{

    if (s1 == d1 && s2 == d2)
    {

        cout << cost[s1][s2] <<"  ";
        return dp[s1][s2] = cost[s1][s2];
    }

    if (dp[d1][d2] != -1)
    {   
        return dp[d1][d2];
    }

    int op1, op2;
    op1 = op2 = INT_MAX;

    if (d1 > s1)
    {
        op1 = mincost(dp, cost, s1, s2, d1 - 1, d2);
    }

    if (d2 > s2)
    {
        op2 = mincost(dp, cost, s1, s2, d1, d2 - 1);
    }


    return dp[d1][d2] = min(op1, op2) + cost[d1][d2];
}

int main()
{
    int cost[100][100], dp[100][100];
    int n, i, j;
    cout << "Enter the size of cost matrix : ";
    cin >> n;

    cout << "Enter the matrix" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            dp[i][j] = -1;
        }
    }
    int s1, s2, d1, d2;
    cout << "Enter the source points : ";
    cin >> s1 >> s2;
    cout << "Enter the destination points : ";
    cin >> d1 >> d2;

    cout << "The minimum cost to get from (" << s1 << "," << s2 << ") to (" << d1 << "," << d2 << ") is " << mincost(dp, cost, s1, s2, d1, d2);
}


// 2 1 3 4
// 3 1 1 10
// 1 6 1 1
// 2 7 4 3

// 0 0

// 2 3