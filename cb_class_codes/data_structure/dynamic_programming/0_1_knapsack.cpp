#include <iostream>
using namespace std;

int knapsack(int dp[][100], int c, int *price, int *wt, int n)
{
    if (n == 0 || c == 0)
    {
        return dp[n][c] = 0;
    }
    if (dp[n][c] != -1)
    {
        return dp[n][c];
    }
    int op1, op2;
    op1 = op2 = INT_MIN;

    if (c >= wt[n - 1])
    {
        op2 = knapsack(dp, c - wt[n - 1], price, wt, n - 1) + price[n - 1];
    }
    op1 = knapsack(dp, c, price, wt, n - 1);
    return dp[n][c] = max(op1, op2);
}

int main()
{

    int price[] = {60, 100, 120};

    int wt[] = {10, 20, 30};
    int capacity = 50;
    int dp[100][100];
    // for (int i = 0; i < 100; i++)
    // {
    //     for (int j = 0; j < 100; j++)
    //     {
    //         dp[i][j] = -1;
    //     }
    // }
    memeset
    int n = sizeof(price) / sizeof(int);
    cout << knapsack(dp, capacity, price, wt, n);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
}