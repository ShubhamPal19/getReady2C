
#include <iostream>

using namespace std;

void spiralprint(int a[100][100], int row, int col)
{

    int sc = 0, sr = 0, ec = col - 1, er = row - 1;
    int i, j;

    while (sc <= ec && sr <= er)
    {

        for (i = sc; i <= ec; i++)
        {
            cout << a[sr][i] << " ";
        }
        sr++;
        for (i = sr; i <= er; i++)
        {
            cout << a[i][ec] << " ";
        }
        ec--;
        if (sr < er)
        {
            for (i = ec; i >= sc; i--)
            {
                cout << a[er][i] << " ";
            }
        er--;
        }
        if (sc < ec)
        {
            for (i = er; i >= sr; i--)
            {
                cout << a[i][sc] << " ";
            }
        sc++;
        }
    }
}

int main()
{

    int a[100][100] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    spiralprint(a, 4, 4);

    return 0;
}