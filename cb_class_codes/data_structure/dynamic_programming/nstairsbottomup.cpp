

#include <iostream>
using namespace std;

int nstairs(int N, int k)
{

    int dp[100],n;
    dp[0] = dp[1] = 1;
   


    for (n = 2; n < k + 1; n++)

        dp[n] = dp[n - 1] * 2;

    for (n = k + 1; n < N + 1; n++)

        dp[n] = dp[n - 1] * 2 - dp[n - k - 1];

    for (int i = 0; i < N + 1; i++)
  
        cout << dp[i] << " for i = " << i << endl;
    
    return dp[n];
}
int main()
{
    int n;
    int k, dp[100];
    cout << "Enter the number of stairs : ";
    cin >> n;

    cout << "Enter the max number of steps one can take at one time : ";
    cin >> k;
    cout << "Number of ways to get at the top is " << nstairs(n, k);
}