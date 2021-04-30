// Given an array, find the subarray which has the largest sum but with a Complication which is that the subarray should contain at least k numbers.

// Input Format
// The First Line Contains the Number Of test Cases. The Second Line Contains the value of N and value of K. The Next line Contains N-space Separated Integers.

// Constraints
// 0 <= k <= N

// Output Format
// Print the Largest Sum for each case separated by a new Line.

// Sample Input
// 1
// 4 2
// -4 -2 1 -3
// Sample Output
// -1
// Explanation
// The largest Sum is because of the Numbers -2 + 1 = -1.

#include <stdio.h>
#include <stdlib.h>

int sum_of_window(int *array, int window_size)
{
    int sum = 0;
    for (size_t i = 0; i < window_size; i++)
    {
        sum = sum + *(array + i);
    }
    return sum;
}
int largest_sum(int *array, int n, int k)
{
    int sum_largest, sum, i, j, window_size = k;
    i = 0;
    j = k-1;
    sum = sum_of_window(array, window_size);
    sum_largest = sum;
    while (1)
    {
        printf("\n %d ", sum_largest);
        if (j == n - 1)
        {
            printf("in if ");
            printf(" (1)in if ");
            printf("  (2  )in if ");

            sum -= *(array + i);
            i++;
            if (i == n - k )
              break;
            while (1)
            {
                printf("i= %d  j= %d", i, j);
                sum -= *(array + j);
                if (sum_largest < sum)
                    sum_largest = sum;

                if (k == j - i)
                    break;
                j--;
            }
        }
        else
        {
            printf("(2)  i= %d  j= %d", i, j);
            printf("in else ");
            sum -= *(array + i);
            i++;
            j++;
            sum += *(array + j);
            if (sum_largest < sum)
                sum_largest = sum;

            while (j != n - 1)
            {
                printf(" (3) i= %d  j= %d", i, j);
                j++;
                sum = *(array + j);
                if (sum_largest < sum)
                    sum_largest = sum;
            }
        }
    }
    if (j==n-1)
    {
        return sum_largest;
    }
    
    while ( 1)
    {
        while ( 1)
        {
         j++;
         sum=sum+*(array+j);
         sum>sum_largest? sum_largest=sum: sum_largest;
         if (j==n-1)
           break;  
        }


        sum-=*(array+i);
        i++;
        while (1)
        {
            j--;
            sum-=*(array+j);
            sum>sum_largest? sum_largest=sum: sum_largest;
            if (j==i+k-1)
            break;
           
        }


        
       
        
        
        
        

    }
    




















    return sum_largest;
}
void main()
{
    int k, n, *array, sum, *sub_array, i;
    printf("\nEnter the value of number of elements and k : ");
    scanf("%d%d", &n, &k);
    array = (int *)malloc(4 * n);
    printf("\nEnter the elements of array : ");
    for (i = 0; i < n; i++)
    {

        scanf("%d", array + i);
    }

    printf("\n before funcall %d", sum);

    sum = largest_sum(array, n, k);
    printf(" \nafter funcall%d", sum);
}