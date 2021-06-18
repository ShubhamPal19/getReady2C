#include <iostream>
using namespace std;

int knapsack(int c, int *price, int *wt, int N)
{
    int dp[100][100]={0};

    
    for (int n = 1; n <= N; n++)
    {
        for (int cap = 1; cap <= c; cap++)
        {
            int op1, op2;
            op1 = op2 = INT_MIN;
            if (cap >= wt[n - 1])

            {
                op1 = price[n - 1] + dp[n - 1][cap - wt[n - 1]];
            }
            op2 = dp[n - 1][cap];
            dp[n][cap] = max(op2, op1);
        }
    }

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
    return dp[N][c];
}

int main()
{

    int price[] = {13, 13, 16};

    int wt[] = {7, 7, 8};
    int capacity = 14;

    int n = sizeof(price) / sizeof(int);
    cout << knapsack(capacity, price, wt, n);
}