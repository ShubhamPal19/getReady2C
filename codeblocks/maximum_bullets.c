// Kaleen Bhaiya is impressed with Guddu and Bablu so he decides to give them some bullets for their guns. He gives N boxes of bullets
//  (Numbered from 1 to N) to guddu and N boxes of bullets(Numbered from 1 to N) to Bablu.

// Now Kaleen Bhaiya puts some conditions:

// Guddu can take maximum A boxes of bullets from his set of boxes and Bablu can take maximum B boxes of bullets from his set of boxes.
// Only one of them can take box with same number i.e if Guddu takes box 1 from his set then Bablu can't take box 1 from his set.
// They have to start from box 1 and go till box N.
// They cannot skip any box and they cannot go back.
// Guddu and Bablu are brothers so they decides to take the maximum amount of bullets and will divide them afterwards but Guddu is weak
// in studies and Bablu bhaiya needs to help Golu for college elections so they asked you for help and in return they will give you a Katta for free.

// Input Format
// First line will contain N, A, B. The second line contains N integers. The ith integer represents number of bullets in ith box given to Guddu.
//  The third line also contains N integers. The ith integer represents number of bullets in ith box given to Bablu.

// Constraints
// 1 ≤ N ≤ 5000
// 0 ≤ A,B ≤ 5000
// N <= A+B
// 0 ≤ Ai ≤ 10^9

// Output Format
// Print a single integer representing the maximum bullets they can get.

// Sample Input
// 5 3 4
// 8 2 5 3 7
// 8 3 4 6 2
// Sample Output
// 29
// Explanation
// Guddu will take boxes with number 1, 3, 5. Bablu will take boxes with number 2, 4.

#include <stdio.h>
#include <stdlib.h>

int *bullet1, *bullet2, n, a, b, *box_array; // box array will store two values , 0 and 1, the index which have value 1 will be the box number taken by guddu, and 0 for bablu.

void printresult()
{
    printf("\nGuddu will take boxes with number : ");
    for (size_t i = 0; i < n; i++)
    {
        if (*(box_array + i))
        {
            printf("%d  ", i + 1);
        }
    }
    printf("\nBablu will take boxes with number : ");
    for (size_t i = 0; i < n; i++)
    {
        if (*(box_array + i) == 0)
        {
            printf("%d  ", i + 1);
        }
    }
}
void choose_boxes()
{
    int x, y;
    x = a;
    y = b;
    for (size_t i = 0; i < n; i++)
    {
        if (x == 0)
        {
            return;
        }
        if (y == 0)
        {
            *(box_array + i) = 1;
            continue;
        }

        if (*(bullet1 + i) > *(bullet2 + i))
        {
            *(box_array + i) = 1;
            x--;
        }
        else if (*(bullet1 + i) < *(bullet2 + i))
        {
            y--;
        }

        else
        {
            if (x > y)
            {
                *(box_array + i) = 1;
                x--;
            }
            else
                y--;
        }
    }
}

void main()
{
    printf("Enter the number of boxes, A and B (eg. 6 4 3): ");
    scanf("%d%d%d", &n, &a, &b);

    bullet1 = (int *)calloc(n, 4);
    bullet2 = (int *)calloc(n, 4);
    box_array = (int *)calloc(n, 4);

    printf("Enter the number of in each box for Guddu : ");

    for (size_t i = 0; i < n; i++)
    {

        scanf("%d", (bullet1 + i));
    }

    printf("Enter the number of in each box for Bablu : ");

    for (size_t i = 0; i < n; i++)
    {

        scanf("%d", (bullet2 + i));
    }

    choose_boxes();
    printresult();
}