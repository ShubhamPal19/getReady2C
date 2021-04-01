// Annie is the talk of the town, who recently won the prize for being the most beautiful woman of her town. Due to her achievement, she has become Dream girl of the youth.
// So, many people in the town are trying to propose her, but She has her own demands and only if the demands are satisfied, she will accept the proposal. She loves two types of chocolates a and b, 
//and she wants someone to gift her d chocolates during the act of proposing. You have infinite supply of boxes of chocolates of type a and b, box of type a contains n chocolates whereas box of type b contains m chocolates. You can gift her d chocolates by using boxes of both the types.
// (You cannot use any box partially).

// Now, You have to find the number of ways in which you can impress her.

// Input Format
// The first line of input consists of an integer T denoting the number of test cases. Each test case consists of only one line containing three space separated integers n(Number of chocolates in box of type a), m(Number of chocolates in box of type b) and d.

// Constraints
// 1 ≤ T ≤ 10^5
// 1 ≤a < b ≤ 10^9
// 0 ≤ d ≤ 109

// Output Format
// For each test case, print the answer in a separate line.

// Sample Input
// 3
// 2 3 7
// 4 10 6
// 5 1 5

// Sample Output
// 1
// 0
// 2


// Explanation
// Test case 1:
// 7 chocolates can only be achieved by using 2 boxes of type a and 1 box of type b.
// Test case 2: No combination of boxes exist to satisfy the value of d.
// Test case 3: 5 chocolates can be achieved by using 2 combinations.
//     1) -> 1 box of type a and 0 box of type b.
//     2)-> 0 box of type a and 5 boxes of type b.  




#include <stdio.h>
#include <stdlib.h>




int find_ways(int  n, int  m , int  d)
{

    int i,remainig,count=0;
    i=0;

    while (i*n<=d)
    {
        if((d-i*n)%m==0)
            count++;
        i++;
    }
    return count;
}

void main()

{
    int t,*m,*n,*d,i;
    

    printf("\nEnter the test case : ");
    scanf("%d",&t);
    m=(int *)malloc(sizeof(int)*t);
    n=(int *)malloc(sizeof(int)*t);
    d=(int *)malloc(sizeof(int)*t);

    for ( i = 0; i < t; i++)
    {
        printf("\nEnter the data for test case %d :  ",i+1);
        scanf("%d%d%d",n+i,m+i,d+i);
       
    }

    for ( i = 0; i < t; i++)
    {
       printf("\nThe number of ways to impress in test case %d is %d ",i+1,find_ways(*(n+i),*(m+i),*(d+i)));
    }
    
    

}