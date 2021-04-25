
#include <stdio.h>
#include <stdlib.h>


void printarray(int * array , int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        printf(" %d ",*(array+i));
    }
    
}
void swap(int * a, int * b)
{
    int temp;
    temp= *a;
    *a= *b;
    *b=temp;

}
void recursive_insertion_sort(int * array,int n)
{
    if(n==0)
    {
        return ;
    }

    recursive_insertion_sort(array,n-1);
    while((  *(array +n) < *(array+n-1) ) )
    {
        swap(array+n,array+n-1);
        if (n==1)
            return;
        n--;
    }

}

void main()
{
    int n , i, * array;

    printf("\nEnter the number of  elements in array : ");
    scanf("%d",&n);
    array= (int * )malloc(4*n);
    printf("%d",sizeof(int));

    printf("\nEnter the elements of array : ");

    for ( i = 0; i < n; i++)
    {
        scanf("%d",array+i);
    }

    printf("\nThe given array is : ");
    printarray(array,n);
    recursive_insertion_sort(array,n);
    printf("\nThe sorted array is : ");
    printarray(array,n);
    
}