// you are given two arrays a[m+n] and b[m]. a has first elements sorted in increasing order and rest of array is empty.
// b has m elements sorted in increasing order. you have to merge two array in array a. and result should be sorted;

#include <iostream>

using namespace std;

int main()
{

    int a[10] = {2, 7, 9, 11};
    int b[6] = {1, 3, 4, 5, 6, 77};
    int n, m, i, j, k;
    m = sizeof(b) / sizeof(b[0]);
    n = sizeof(a) / sizeof(a[0]) - m;
    cout << n << "  " << m;

    i = n - 1;
    j = m - 1;
    k = m + n - 1;
    while (j >= 0 && i >= 0)
    {

        if (a[i] > b[j])
        {
            a[k--] = a[i--];
        }

        else
        {
            a[k--] = b[j--];
        }
    }

    while (j != -1)
    {
        a[k--] = b[j--];
    }
    cout << "\nSorted array is : ";

    for (size_t i = 0; i < m + n; i++)
    {
        cout << a[i] << " " ;
    }
    return 0;
}
