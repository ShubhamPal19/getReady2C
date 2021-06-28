// Finquest Event hosted by ABC Company is all about share market and who can make the best profit out of it. Imagine that your algorithms have become so good at predicting the market that you now know what the share price of Das Motors Inc. (DM) will be for the next N days. Each day, you can either buy one share of DM, sell any number of shares of DM that you own, or not make any transaction at all. What is the maximum profit you can obtain with an optimum trading strategy?

// Input Format
// The first line contains the number of test cases T. T test cases follow: The first line of each test case contains a number N. The next line contains N integers, denoting the predicted price of DM shares for the next N days.

// Constraints
// 1 <= T <= 10 1 <= N <= 50000 All share prices are between 1 and 100000

// Output Format
// Output T lines, containing the maximum profit which can be obtained for the corresponding test case.

// Sample Input
// 3
// 3
// 5 3 2
// 3
// 1 2 100
// 4
// 1 3 1 2
// Sample Output
// 0
// 197
// 3
// Explanation
// For the first case, you cannot obtain any profit because the share price never rises. For the second case, you can buy one share on the first two days, and sell both of them on the third day. For the third case, you can buy one share on day 1, sell one on day 2, buy one share on day 3, and sell one share on day 4.


#include<iostream>
#include<climits>
using namespace std;

int * a,n;


int profit(int day,int shares, int cost, int dp[])
{
    if(day==n-1)
    {
        return dp[day*n+shares]= cost+shares*a[day];

    }


    if (dp[day*n+shares]!=INT_MIN)
    {
        return dp[day*n+shares];
    }
    int op1,op2,op3;
    op1=op2=op3=INT_MIN;
    
    op1=profit(day+1,shares+1,cost-a[day],dp);
    op2=profit(day+1,0,cost+a[day]*shares,dp);
    op3=profit(day+1,shares,cost,dp);

    return dp[day*n+shares]=max(op1,max(op3,op2));

}
int main()
{
    cout<<32<<endl;
   
    int t;
    int *dp;
    cin>>t;


    while (t--)
    {
        cin>>n;
        a=new int[n];
        dp=new int[n*n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            for (int j = 0; j < n; j++)
            {
                dp[i*n+j]=INT_MIN;
            }
            
        }

        
        cout<<profit(0,0,0,dp)<<endl;

        delete []a;
        delete []dp;

    }
    
    return 0;

}