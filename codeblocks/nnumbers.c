// Find first N numbers such that a number and its reverse are divisible by sum of its digits

#include <stdio.h>
#include <math.h>

void reverse_sum_num(int n, int *reverse, int *sum)
{
    *sum = 0;
    *reverse = 0;

    while (n != 0)
    {
        *sum = (*sum) + n % 10;
        *reverse = (*reverse) * 10 + n % 10;
        n = n / 10;
    }
}

void main()
{
    int n, sample, reverse, sum;
    printf("\nEnter value of N : ");
    scanf("%d", &n);
    sample = 1;

    printf("\nThe n numbers are-\n ");
    while (n != 0)
    {
        reverse_sum_num(sample, &reverse, &sum);

        if (reverse % sum == 0 && sample % sum == 0)
        {
            printf(" %d", sample);
            n--;
        }
        sample++;
    }
}
