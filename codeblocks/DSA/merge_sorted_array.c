// Merge Without Extra Space

#include <stdio.h>

void print_array(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void merge_array(int a1[], int a2[], int l1, int l2)
{
    int i, j, temp;

    i = 0;
    j = 0;

    while (i < l1)
    {
        if (a1[i] > a2[0])
        {
            temp = a1[i];
            a1[i] = a2[0];
            j = 0;
            while (a2[j + 1] < temp)
            {
                a2[j] = a2[j + 1];
                if (j == l2 - 1)
                    break;
                j++;
            }
            a2[j] = temp;
        }
        i++;
    }

    print_array(a1, l1);
    print_array(a2, l2);
}

void main()
{

    int a1[] = {3, 4,  7, 9, 33},
        a2[] = {2, 5, 6, 44, 45, 49};

    int l1 = sizeof(a1) / sizeof(int);
    int l2 = sizeof(a2) / sizeof(int);

    merge_array(a1, a2, l1, l2);
}