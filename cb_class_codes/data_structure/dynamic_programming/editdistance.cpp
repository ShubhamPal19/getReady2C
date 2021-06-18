#include <iostream>
using namespace std;

int editdistance(int dp[][100], string s1, string s2, int i, int j)
{
    if (i == 0)
    {
        return dp[i][j] = j;
    }
    if (j == 0)
    {
        return dp[i][j] = i;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s1[i - 1] == s2[j - 1])
    {
        return dp[i][j] = editdistance(dp ,s1, s2, i - 1, j - 1);
    }
    int op1, op2, op3;
    op1 = 1 + editdistance(dp, s1, s2, i - 1, j - 1);
    op2 = 1 + editdistance(dp, s1, s2, i, j - 1);
    op3 = 1 + editdistance(dp, s1, s2, i - 1, j);
    return dp[i][j] = min(op1, min(op2, op3));
}

int main()
{
    // string s1 = "cat", s2 = "cut";
    string s1 = "sunday", s2 = "saturday";
    int dp[100][100];
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << endl
         << editdistance(dp, s1, s2, s1.length(), s2.length());
}