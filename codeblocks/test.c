// use of multiline macro

#include <stdio.h>
#define p                             \
    printf("this is transformation"); \
    printf("\n next line");           \
    printf("\nlast line ");           \ 
    int x = 5;

void main()
{

    p;

    printf("\n%d", x);
    
    x  =  (x++);
    printf("\n%d",x);

    
}