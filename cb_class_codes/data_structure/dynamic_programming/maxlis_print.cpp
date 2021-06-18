#include<iostream>

using namespace std;


void printlis(int a[],int n)
{
    int dp[100];
    for (int i = 0; i < 100; i++)
    {
        dp[i]=1;
    }
    for (int i =n-1; i >=0; i--)
    {
        for (int j = n-1; j > i; j--)
        {
            if (a[i]<a[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
            
        }
        
    }
    int maxindex=0;
    for (int j = 0; j < n; j++)
    {
        if (dp[maxindex]<dp[j] )
        {
           maxindex=j;
        }
        
    }
 int  count= dp[maxindex],maxelement=a[maxindex]-1;
   for (int i = maxindex; i < n; i++)
   {
       if (count==dp[i] && maxelement < a[i])
       {
           count--;
           maxelement=a[i];
           cout<<a[i]<< "  ";
       }
       
       
   }
   cout<<endl;
    
     
}
int main()
{
    int array[]={ 2,3,1,4,5,0,6,9,8,19,18};
    int n=sizeof(array)/sizeof(int);

  printlis(array,n);
}