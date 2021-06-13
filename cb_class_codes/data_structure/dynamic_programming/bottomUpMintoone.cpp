
#include <iostream>
using namespace std;

// you can perform N/3,N/2 and N-1; to get 1 from n. Now find the minimum number of steps required to get 1;

//bottomup approach

int minsteps(int n)
{

    int *dp = new int[n + 1], i;
    dp[1] = 0;
    int op1, op2, op3;
    for (i = 2; i < n + 1; i++)
    {
        op1=op2=op3=INT_MAX;
        op1 = dp[i - 1] ;
        if (i % 3 == 0)
        {
            op3 = dp[i / 3] ;
        }
        if (i % 2 == 0)
        {
            op2 = dp[i / 2];
        }
        dp[i] = min(min(op1, op2), op3)+1;
    }

    for (i = 1; i < n + 1; i++)
    {
        cout << dp[i] << "   ";
    }
    cout << endl;

    return dp[n];
}

int main()
{
    int n =1025;
    

    cout << "Minimum steps to 1 from";
    cout << "Minimum steps to 1 from " << n << " is " << minsteps(n);
    return 0;
}