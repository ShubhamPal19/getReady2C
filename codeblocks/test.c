// use of multiline macro

#include <stdio.h>
#define p                             \
    printf("this is transformation"); \
    printf("\n next line");           \
    printf("last line ");             \
    int x = 5;

void main()
{

    p;

    printf("%d", x);
}