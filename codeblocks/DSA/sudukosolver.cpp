// 0 4 0 1 8 0 0 0 0
// 3 2 6 0 0 0 0 0 0
// 0 1 0 9 0 0 0 0 0
// 0 0 3 0 0 0 0 0 4
// 0 0 0 5 0 7 0 0 8
// 7 0 0 0 0 0 1 0 0
// 0 0 0 0 0 1 6 2 0
// 0 0 0 0 6 0 0 0 0
// 4 0 0 0 2 0 0 3 0

#include <iostream>

using namespace std;

bool isvalid(int a[][9], int i, int j, int value)
{
    for (int t = 0; t < 9; t++)
    {
        if (a[t][j] == value || a[i][t] == value)
        {
            return false;
        }
    }

    int I, J, x, y;
    x = (int)((i / 3)) * 3;

    y = ((int)(j / 3)) * 3;

    for (I = x; I < x + 3; I++)
    {
        for (J = y; J < y + 3; J++)
        {
            if (a[I][J] == value)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudoku_solver(int sudo[][9], int i, int j, int n)
{
    if (i == n)
    {
        for (size_t i = 0; i < 9; i++)
        {
            for (size_t j = 0; j < 9; j++)
            {
                cout << sudo[i][j] << "  ";
            }
            cout << endl;
        }
        return true;
    }

    if (j == n)
    {
        return sudoku_solver(sudo, i + 1, 0, 9);
    }

    if (sudo[i][j] != 0)
    {
        return sudoku_solver(sudo, i, j + 1, n);
    }

    for (int value = 1; value <= n; value++)
    {

        if (isvalid(sudo, i, j, value))
        {
            sudo[i][j] = value;

            if (sudoku_solver(sudo, i, j + 1, n))
            {
                return true;
            }
            sudo[i][j] = 0;
        }
    }

    return false;
}
int main()
{
    int sudo[9][9];
    cout << "Enter the sudoku to be solved (fill 0 at blank places) " << endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudo[i][j];
        }
    }

    sudoku_solver(sudo, 0, 0, 9);
    cout << endl
         << "the solution is " << endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudo[i][j] << "  ";
        }
        cout << endl;
    }
}