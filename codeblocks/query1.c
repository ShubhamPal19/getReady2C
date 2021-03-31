// Your are given Q queries. Each query consists of 2 integers, L and R. For each integer K, in the range [L,R],
//  you have to find the sum of products of all pairs (a1, a2), such that a1 is an odd divisor of K and a2 is an even divisor of K. For each query, find the sum of this value over range [L,R].

// Input Format
// First line contains a single integer, Q. Next Q lines contain 2 integers each, L and R.

// Constraints
// 1<=Q<=10^5 1<=L<=R<=10^5

// Output Format
// Print the answer to the query modulo 109+7.

// Sample Input
// 4
// 1 100000
// 3 3
// 4 4
// 4 10000
// Sample Output
// 585665833
// 0
// 6
// 179580982
// Explanation
// For 3rd query, [4,4], odd divisors = 1, even divisors = 2, 4. Answer = 2 + 4 = 6.

#include <stdio.h>

#include <stdlib.h>

int sum_of_product(int k)
{
    int i, j, sum = 0;
    for (i = 1; i <= k; i++)
    {
        if ((k % i == 0) && (i % 2 == 1))
        {
            for (j = 2; j <= k; j++)
            {
               
                if ((k % j == 0) && (j % 2 == 0))
                {
                    sum = sum + i * j;
                }
            }
        }
    }

    return sum;
}

int final_sum(int l, int r)
{
    
    int sum = 0, k = l;

    while (k <= r)
    {
    printf("  %d == %d ",k,r);
      
        sum = sum + sum_of_product(k);

        k++;
    }
    return sum;
}

void print_output(int *l, int *r, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {  
        printf("     in loop 1    ");
        printf("\nResult of query %d is : %d ", i, final_sum(*(l + i), *(r + i)));
    }
}

void main()
{
    int n, i, *l, *r, k;
    printf("\nEnter the number of queries in the problem : ");
    scanf("%d", &n);

    l = (int *)malloc(sizeof(int) * n);
    r = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the value of L and R for query %d : ", i);
        scanf("%d%d", l + i, r + i);
    }

    print_output(l, r, n);
}

