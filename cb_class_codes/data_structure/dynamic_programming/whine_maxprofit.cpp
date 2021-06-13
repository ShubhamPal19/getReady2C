#include <iostream>
using namespace std;



//top down approach
int max_profitt( int dp[][100],int day, int * price,int s ,int e)
{

    if (s>e)
    {
        return dp[s][e]=0;
    }
    
    if (dp[s][e]!=-1)
    {
        return dp[s][e];
    }
    int op1= max_profitt(dp,day+1,price,s+1,e)+price[s]*day;
    int op2= max_profitt(dp,day+1,price,s,e-1)+price[e]*day;
    
    dp[s][e]=max(op1,op2);

    return dp[s][e];

}

int main()
{
    int price[]={2,3,5,1,4,6,3,8,5,7,4};
    int days= sizeof(price)/4;
    cout<< days<< endl;
    int dp[100][100];
    for (int i = 0; i < days+1; i++)
    {
        for (int j = 0; j < days+1; j++)
        {
              dp[i][j]=-1;
        }
        
      
    }
    

    cout << "Maximum profit in total is : "<< max_profitt(dp,1,price,0,days-1);


}



