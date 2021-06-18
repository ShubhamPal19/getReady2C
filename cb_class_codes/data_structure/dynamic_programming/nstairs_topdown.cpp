

#include <iostream>
using namespace std;


int nstairs(int dp[],int n,int k)
{

    if ( n==1,n==0)
    {
        return dp[n]= 1;
    }
    if (dp[n]!=-1)
    {
        return dp[n];
    }
    int ways=0;
    for (int i = n-1; i >= n-k && i>=0; i--)
    {
        ways+= nstairs(dp,i,k);
    }
    
    return dp[n]=ways;
    

}
int main()
{
    int n;
    int k,dp[100];
    cout << "Enter the number of stairs : ";
    cin>>n;
    for (int i = 0; i < n+1; i++)
    {
      dp[i]=-1;
    }
    
    cout << "Enter the max number of steps one can take at one time : ";
    cin>>k;
    cout<<"Number of ways to get at the top is "<< nstairs(dp ,n,k)<<endl;

    for (int i = 0; i < n+1; i++)
    {
       cout<< dp[i]<<" for i = "<<i<<endl;
    }
}