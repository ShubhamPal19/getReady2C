// Rohan’s city can be represented as an infinite cartesian coordinate system. The City has a strange road system.
// It consists of a single road connecting all the points in the plane. The road starts from (0,0) and form the following pattern:-
//  (0,0) to (1,0), (1,0) to (1,1), (1,1) to (-1,1), (-1,1) to (-1,-1), (-1,-1) to (2,-1), (2-1) to (2,2) and so on. Rohan want to go from (0,0) to (X,Y).
//  Can you find the number of turns required to go from (0,0) to (X,Y) following the above described road?

// Input Format
// First line of the input contains two integers X and Y.

// Constraints
// -100<=X,Y<=100

// Output Format
// Print a single integer representing number of turns required.

// Sample Input
// -1 -1
// Sample Output
// 3
// Explanation
// First turn at (1,0). Second at (1,1). Third at (-1,1). Then we will arrive at (-1,-1). So, total turns will be 3.

#include <stdio.h>
#include <stdlib.h>

void next_turn(int xc, int yc, int *x_next, int *y_next)
{
    *x_next=xc;
    *y_next=yc;

    if(xc==yc)
    {
        if (xc>0)
            *x_next=xc*(-1);
        else 
            *x_next=xc*(-1)+1;
    }
    else if (xc>0)
    {
        *y_next= xc;
    }
    else 
        *y_next=yc * (-1);
}

int count_turns(int x, int y)
{
    int xc = 0, yc = 0, x_next, y_next;
    int turns = 0;

    while (1)
    {
        next_turn(xc, yc, &x_next, &y_next);

        if (yc == y)
        {
            if (y > 0)
            {
                if (x >= x_next && x < xc)
                    return turns:
            }
            else
            {
                if (x <= x_next && x >= xc)
                    return turns;
            }
        }
        else if (xc == x)
        {
            if (x > 0)
            {
                if (y <= y_next && y > yc)
                    return turns;
            }
            else
            {
                if (y >= y_next && y < yc)
                {
                    return turns;
                }
            }
        }

    xc=x_next;
    yc=y_next;
    turns++;
    }
}

void main()
{
    int x, y;
    printf("\nEnter the coordinates input : ");
    scanf("%d%d", &x, &y);
    printf("The number of turns taken by user to reach the destination is  %d.", count_turns(x, y));
}
