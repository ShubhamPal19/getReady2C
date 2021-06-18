#include<iostream>

using namespace std;


int lis(int a[],int n)
{
    int dp[100];
    for (int i = 0; i < 100; i++)
    {
        dp[i]=1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i]>a[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
            
        }
        
    }
    int ans=1;
    for (int j = 0; j < n; j++)
    {
        if (ans<dp[j])
        {
            ans=dp[j];
        }
        
    }
    return ans;
     
}
int main()
{
    int array[]={ 2,3,1,4,5,0,6,9,8,19,18};
    int n=sizeof(array)/sizeof(int);

    cout<<"Lis is " << lis(array,n)<<endl;
}