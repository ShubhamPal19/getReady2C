#include <iostream>
using namespace std;




int mindenbottomUp(int n,int *coin, int count)
{
  int *dp= new int[n+1];
  dp[0]=0;
  for (int i = 1; i < n+1; i++)
  {
      int small_amount,ans=INT_MAX;
      for (int j = 0; j < count; j++)
      {
         small_amount= i-coin[j];
         if (small_amount < 0)
         {
             continue;
         }

         if (dp[small_amount]<ans )
         {
             ans=dp[small_amount]+1;
         }
         
      }

      dp[i]=ans;
      cout << "current ans for   "<< i<< "   is   " <<ans << endl;
      
      
  }
  
  return dp[n];
  

}

int main(int argc, char const *argv[])
{
    int n = 129;
    int coin[] = {1, 7, 10};
    
    cout << "\ncoin = " << mindenbottomUp(n, coin, sizeof(coin) / 4);
    return 0;
}
