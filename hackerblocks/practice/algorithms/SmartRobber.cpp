// A professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping him from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money he can rob tonight without alerting the police.

// Input Format
// First line contains integer t as number of testcases. Second line contains integer n as size of array. Third line contains a single integer as element of array.

// Constraints
// None

// Output Format
// Print the maximum money as output.

// Sample Input
// 1
// 4
// 1 2 3 1
// Sample Output
// 4


#include<iostream>
#include<cstdlib>

using namespace std;

int solution(int * a,int i,int n,int dp[])
{   

    if (i>=n)
    {
        return 0;
    }
    
    if (dp[i]!=-1)
    {
        return dp[i];
    }
    int op1= a[i]+solution(a,i+2,n,dp);
    int op2= a[i+1]+solution(a,i+3,n,dp);

    return dp[i]=max(op1,op2);
    
    
}
int main()
 {
     int t;
     int n;
     int *a,*dp;
     cin>>t;
     int *sol=new int[t];
     for (int  i = 0; i < t; i++)
     {
         cin>>n;
         a = new int[n];
         dp = new int[n];


         for (int j = 0; j < n; j++)
         {
             dp[j]=-1;
             cin>>a[j];
         }

        cout<<solution(a,0,n,dp)<<endl;
        
    }

     
     
     

     return 0;
     

 }

