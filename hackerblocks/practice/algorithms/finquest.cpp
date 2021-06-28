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



int find_max(int I, int J)
{
    int max=I;
    for (int i = I+1; i <=J; i++)
    {
        if (a[max]<a[i])
        {
            max=i;
        }   
    }

    return max;
    
}

long long int  profit()
{   
    long long int   max=find_max(0,n-1);
    long long int  shares=0,profit=0;

    for ( int i = 0; i < n; i++)
    {
        
        if (max==i )
        {
            profit+=shares*a[i];
            shares=0;
             max=find_max(i+1,n-1);
        }
        else
        {
        profit-= a[i];
        shares++;
        }
        

    }
    return profit;
    

}
int main()
{

    int t;

    cin>>t;


    while (t--)
    {
        cin>>n;
        a=new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        cout<<profit()<<endl;

        delete []a;

    }
    
    return 0;

}

// #include<iostream>
// #include<climits>
// using namespace std;

// int * a,n;


// int profit(int day,int shares, int cost)
// {
//     if(day==n-1)
//     {
//         return cost+shares*a[day];

//     }

//     int op1,op2,op3;
//     op1=op2=op3=INT_MIN;


//     op1=profit(day+1,shares+1,cost-a[day]);
//     op2=profit(day+1,0,cost+a[day]*shares);
//     op3=profit(day+1,shares,cost);

//     return max(op1,max(op3,op2));

// }
// int main()
// {

//     int t;

//     cin>>t;


//     while (t--)
//     {
//         cin>>n;
//         a=new int[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
        
//         cout<<profit(0,0,0)<<endl;

//         delete []a;

//     }
    
//     return 0;

// }