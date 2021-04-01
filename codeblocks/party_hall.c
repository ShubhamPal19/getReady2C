// Given an array of meeting time intervals consisting of start and end times [[S1,E1],[S2,E2],…] (SI < EI), find the minimum number of party halls required.

// Input Format
// Take input N
// Next N line consists of two space-separated integers SI and EI

// Constraints
// None

// Output Format
// print minimum required room

// Sample Input
// 5
// 1 4
// 2 5
// 3 6
// 10 11
// 11 12
// Sample Output
// 3

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int e;
    struct node *next;
};

int max = 0, n;
struct node *head = NULL;


void remove_node()
{

    head = head->next;
    n--;
}

void insert(int s, int e)
{
    struct node *temp, *current;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->e = e;

    while (1)
    {
        if (head == NULL)
            break;

        if (head->e < s)
        {
            remove_node();
        }
        else
            break;
    }

    if (head == NULL)
    {
        head = temp;
    }
    else
    {

        current = head;
        while (current->e < e && current->next != NULL)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
    n++;
    if (max < n)
    {
        max = n;
    }
}

int party_hall(int *s, int *e, int t)
{

    for (int i = 0; i < t; i++)
    {
        insert(*(s + i), *(e + i));
    }
    return max;
}

void main()
{

    int t, *e, *s, *flag, i;

    printf("\nEnter the number  of events : ");
    scanf("%d", &t);
    s = (int *)malloc(sizeof(int) * t);
    e = (int *)malloc(sizeof(int) * t);

    for (i = 0; i < t; i++)
    {
        printf("\nEnter the meet starting time and ending time %d :  ", i + 1);
        scanf("%d%d", s + i, e + i);
    }

    printf("\nThe required number of party hall is %d. ", party_hall(s, e, t));
}
