// There is a given binary matrix, we need to find if there exists any rectangle or square in the given matrix whose all four corners are equal to 1.

// Input Format
// First line contains N, size of the matrix

// Next N lines contains N integers each denoting the matrix elements.

// Constraints
// 4 <= N <= 100

// Output Format
// Print "true" or "false" (without the quotes).

// Sample Input
// 5 5
// 1 0 0 1 0
// 0 0 1 0 1
// 0 0 0 1 0
// 1 0 1 0 1
// 1 0 1 0 0

// Sample Output
// true
// Explanation
// Yes as there exists-

// 1 0 1
// 0 1 0
// 1 0 1



#include<stdio.h>
#include<stdlib.h>



int check_for_rectangle(int * A,int n)
{
    int i,j,k,l,count;
    count=0;
    for(i=0;i<n;i++)
    {
        for ( j = 0; j < n; j++)
        {
          
            if(*(A+ n*i+j))
            {
                k=j+1;
                while (k<n)
                {
                   if (*(A+n*i+k))
                   {
                       l=i+1;
                       while (l<n)
                       {
                          if (*(A+l*n+k))
                           {
                              if (*(A+l*n+j))
                              {
                                 count++;
                              }
                            }

                            l++;
                          
                        }
                       
                       
                    }
                    k++;
                   
                }
                
            }
        }
        
    }

    return count;
}



void main()
{

    int n,i,j,*A,count;
    printf("\nEnter the size of sqaure matrix : ");
    scanf("%d",&n);

    A = (int * )malloc(n*n*sizeof(int));
    printf("\n Enter the binary matrix : \n");

   for ( i = 0; i < n; i++)
   {
       for ( j = 0; j < n; j++)
       {
           scanf("%d", (A+n*i+j));
       }
    }

    count=check_for_rectangle(A,n);

    count==0?  printf("\nThere is no rectangle in the matrix."):printf("\nThe number of rectangle or square is %d. ",count);
  
   
}

