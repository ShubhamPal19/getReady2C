
   
#include <iostream>
using namespace std;

int max_profitt(int days, int *price)
{
    
    int i, j;
    int dp[100][100]={0};
 
    for ( i = 0; i < days; i++)
    {
        for ( j = 0; j < days; j++)
        {
            cout<< dp[i][j]<<"  ";

        }
        cout << endl;

        
    }
    

    for (i = days - 1; i >= 0; i--)
    {
        for (j = i ; j < days; j++)
        {

            int days_left = days - j + i;
            int op1 = dp[i + 1][j] + price[i] * days_left;
            int op2 = dp[i][j - 1] + price[j] * days_left;
            dp[i][j] = max(op1, op2);

             cout<< dp[i][j]<<"  ";

        }
        cout << endl;

       
    }



    return dp[0][days - 1];
}

int main()
{
    int price[] = {2, 3, 5, 1, 4};
    int days = sizeof(price) / 4;

    cout << "Maximum profit in total is : " << max_profitt(days, price);
}

// 24
// 29  41
// 37  40  48
// 23  43  45  50