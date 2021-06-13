#include <iostream>
using namespace std;

// //top down approach
// int mindenomination(int n, int arr[], int *coin, int count)
// {

//     if (n == 0)
//         return arr[n] = 0;
//     if (arr[n] != -1)
//         return arr[n];

//     int ans = INT_MAX;
//     int current_ans=INT_MAX;
//     for (size_t i = 0; i < count; i++)
//     {
//         int smalln = n - coin[i] ;
//         if (smalln < 0)
//         {
//             continue;
//         }
//         current_ans=mindenomination(smalln,arr,coin,count);

//         if (current_ans < ans && current_ans != INT_MAX)
//         {
//             ans = current_ans + 1;
//         }
//     }
//     return arr[n] = ans;
// }


int mindenbottomUp(int n,int *coin, int count)
{
  int *dp= new int[n+1];
cout << " here ";

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
    int n = 19, *arr;
    int coin[] = {1, 7, 10};
     arr = new int[n];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    // cout << "coin = " << mindenomination(n, arr, coin, sizeof(coin) / 4);
    cout << "\ncoin = " << mindenbottomUp(n, coin, sizeof(coin) / 4);
    return 0;
}
