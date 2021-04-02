
// PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries between a and b (inclusive) , However due to shortage of time he can't visit each and every country ,
//So PM Modi decides to visit only those countries,for which country number has two divisors. So your task is to find number of countries Mr. Modi will visit.

// Input Format
// The first line contains N , no of test cases. The next N lines contain two integers a and b denoting the range of country numbers.

// Constraints
// a<=1000000 & b<=1000000.
// N<=1000

// Output Format
// Output contains N lines each containing an answer for the test case.

// Sample Input
// 2
// 1 10
// 11 20
// Sample Output
// 4
// 4
// PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
// For the second testcase , he chooses countries with numbers 11,13,17 and 19.

#include <stdio.h>
#include <stdlib.h>

struct prime_num
{
    int p;
    struct prime_num *next;
};
struct prime_num *head;

void insert(struct prime_num **tail, int p)
{
    (*tail)->next = (struct prime_num *)malloc(sizeof(struct prime_num));
    (*tail) = (*tail)->next;
    (*tail)->p = p;
    (*tail)->next = NULL;
}

int is_prime(int n)
{

    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    struct prime_num *current, *temp;
    int flag1 = 1, flag2;
    flag2 = 1;
    current = head;
    while (current->p <= n / 2 + 1)
    {
        if (n % current->p == 0)
            return 0;

        if (current->next == NULL)
        {
            flag1 = 0;
            break;
        }
        current = current->next;
    }
    if (flag1)
        return 1;

    for (int i = current->p + 1; i < n; i++)
    {
        temp = head;
        flag2 = 1;

        while (temp->p <= i / 2 + 1)
        {
            if (i % temp->p == 0)
            {
                flag2 = 0;
                break;
            }
            if (temp->next == NULL)
                break;

            temp = temp->next;
        }
        if (flag2)
        {
            insert(&current, i);
            if (n % i == 0)
            {
                return 1;
            }
        }
    }
    return 1;
}

void print_output(int *a, int *b, int t)
{
    int i, j, count;
    for (i = 0; i < t; i++)
    {
        count = 0;
        for (j = *(a + i); j <= *(b + i); j++)
        {
            if (is_prime(j))
                count++;
        }
        printf("\nThe number of countries which will be visited is for test case %d is %d. ", i + 1, count);
    }
}

void main()
{
    int t, *a, *b, i;
    printf("\nEnter the number of test cases : ");
    scanf("%d", &t);

    a = (int *)malloc(sizeof(int) * t);
    b = (int *)malloc(sizeof(int) * t);
    head = (struct prime_num *)malloc(sizeof(struct prime_num));
    head->next = NULL;
    head->p = 2;
    head->next = (struct prime_num *)malloc(sizeof(struct prime_num));
    head->next->next = NULL;
    head->next->p = 3;

    for (i = 0; i < t; i++)
    {
        printf("\nEnter the value of a and b for test case %d : ", i + 1);
        scanf("%d%d", a + i, b + i);
    }

    print_output(a, b, t);
}

// int country_selected(int n)
// {

//     printf("\nin select contry ");
//     struct prime_num *current, *temp;
//     current = head;
//     while ( current->next != NULL)
//     {
//         printf("\nin 1 while n=%d  the prime is %d ", n, current->p);
//         if (n % (current->p) == 0)
//             return 0;

//         current = current->next;
//     }
//     int i = current->p +1 , flag = 1;
//     while (i <= n)
//     {
//         temp = head;
//         while (temp->p <= i / 2 + 1 && temp->next != NULL)
//         {
//             printf("\n  11   in second while n=%d  i=%d    the prime is %d", n, i, temp->p);
//             if (i % temp->p == 0)
//             {
//                 flag = 0;
//                 break;
//             }
//             temp = temp->next;
//         }

//         if (flag == 1)
//         {
//             printf("\n  12  in second while n=%d  i=%d     the prime is %d", n, i, temp->p);
//             insert(&current, i);
//             printf("\n   13 in second while n=%d  i=%d   %d     ", n, i,current->p);
//         }
//         i++;
//     }
// }
