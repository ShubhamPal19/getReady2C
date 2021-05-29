#include <iostream>
using namespace std;


// merge function without using extra memory;
void merge(int a[], int s, int m, int e)
{
    int i = s, k;
    while (i < m)
    {

        if (a[i] > a[m])
        {
            swap(a[i], a[m]);
            k = m;
            while (a[k] > a[k + 1] && k < e)
            {
                swap(a[k], a[k + 1]);
                k++;
            }
        }
        i++;
    }

}

void mergesort(int a[], int s, int e)
{
    if (s == e)
    {
        return;
    }

    int mid = (s + e) / 2;
    mergesort(a, s, mid);
    mergesort(a, mid + 1, e);
    merge(a, s, mid + 1, e);
}

int main()
{

    int n;
    // cin>> n;

    // int a[]={12,3,31,4,543,7,435,1};
    int a[] = {12, 3, 31, 4, 543, 7, 75, 31, 5, 46, 257, 658, 13, 15, 45, 45, 4645, 65, 757, 67, 654};
    n = sizeof(a) / sizeof(int);

    mergesort(a, 0, n - 1);
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
