// You are given a lucky number n. Lucky numbers are the positive integers whose decimal representations
// contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

// If we sort all lucky numbers in increasing order, what's the 1-based index of n?
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int next_lucky_num(int n)
{
    int temp = n, place = 1;
    while (temp != 0)
    {

        if (temp % 10 == 7)
        {
            n = n - place * 3;
            place = place * 10;
            temp = temp / 10;
        }
        else
        {
            n = n + 3 * place;
            return n;
        }
    }

    return n + place * 4;
}

int find_index(int n)
{
    int index, element = 4;
    index = 1;
    printf("\n the array of lucky numbers is : 4 ");
    while (element != n)
    {

        element = next_lucky_num(element);
        printf(" %d", element);
        index++;
    }
    return index;
}

void main()
{

    int n;
    printf("\nEnter the lucky number : ");
    scanf("%d", &n);

    printf("\nThe index of the lucky number is : %d", find_index(n));
}
