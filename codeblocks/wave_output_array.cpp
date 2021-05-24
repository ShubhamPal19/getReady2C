#include <iostream>

using namespace std;

int main()
{

    int b[][4] = {
        {1, 2, 3, 32},
        {43, 34, 4, 1},
        {4, 5, 6, 9},
        {1,2,3,4}
        };

    int n = 4, i = 0, j = 0, incre_decrement = 1;

    while (j != n)
    {
        for (; i < n && i>-1; i = i + incre_decrement)
        {
            cout << b[i][j] << " ";
        }
        incre_decrement *= -1;
        j++;
        i=i + incre_decrement;
        cout << endl;
    }
    return 0;
}