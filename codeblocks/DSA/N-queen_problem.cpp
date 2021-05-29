// Given chess board of nxn,
// you have to place n queens one in each row so that they do not cut each other.

#include <iostream>
#include <cstdlib>

using namespace std;

bool can_be_placed(int board[], int i, int j, int n)
{

    int k;
    for (k = 0; k < i; k++)
    {
        for (int p = 0; p < n; p++)
        {
            if (board[k * n + p])
            {
                if (p == j)
                    return false;
                else if ((i - k) == abs(j - p))
                    return false;
            }
        }
    }
    if (k == i)
        return true;
}
bool n_queen(int board[], int i, int n)
{

    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(board[i * n + j]) 
                {
                    cout<< "Q  ";

                }     
                else
                   cout<< "-  "  ;
                 }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    for (int k = 0; k < n; k++)
    {

        if (can_be_placed(board, i, k, n) == true)
        {
            board[i * n + k] = 1;
            if (n_queen(board, i + 1, n))
            {
                return true;
            }
            board[i * n + k] = 0;
        }
    }

    return false;
}

int main()
{

    int *board, n;
    cout << "Enter the value of n : ";
    cin >> n;
    cout << endl;

    board = (int *)calloc(n * n, sizeof(int));

   if(!  n_queen(board, 0, n))
   {
       cout << "Not possible to find such a combination."<<endl;
   }
   return 0;
}