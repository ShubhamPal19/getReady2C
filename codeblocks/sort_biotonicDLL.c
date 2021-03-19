
// Sort the given biotonic doubly linked list. A biotonic doubly linked
// list is a doubly linked list which is first increasing and then decreasing.
//  A strictly increasing or a strictly decreasing list is also a biotonic doubly linked list.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int key;
    struct node *next, *previous;
};

void input(struct node **temp)
{
    *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the key : ");
    scanf("%d", &(*temp)->key);
    (*temp)->next = NULL;
    (*temp)->previous = NULL;
    return;
}

void insert(struct node **headref, struct node **tailref, struct node *temp)
{
    if ((*headref) == NULL)
    {
        (*headref) = temp;
        (*tailref) = temp;
        return;
    }

    temp->previous = (*tailref);
    (*tailref)->next = temp;
    (*tailref) = temp;
}

struct node *sort_biotonic(struct node *head, struct node *tail)
{
    struct node *h, *t, *temp;
    h = NULL;
    t = NULL;

    if (head == NULL)
    {
        printf("\nThe linked list is empty :");
        return NULL;
    }
    while (head != tail)
    {
        if (head->key > tail->key)
        {
            tail = tail->previous;

            insert(&h, &t, tail->next);
            tail->next = NULL;
        }
        else
        {
            head = head->next;
            insert(&h, &t, head->previous);
            head->previous = NULL;
        }
    }
    insert(&h, &t, head);
    return h;
}

void printDLL(struct node *head)
{

    printf("\n");

    while (head != NULL)
    {
        printf(" %d ", head->key);
        head = head->next;
    }
}

void main()
{
    int n, i;
    struct node *head, *tail, *temp;
    head = NULL;
    tail = NULL;

    printf("\nEnter the number of elements in the data : ");
    scanf("%d", &n);
    printf("\nEnter the data : \n");

    for (i = 0; i < n; i++)
    {
        input(&temp);
        insert(&head, &tail, temp);
    }

    printDLL(head);
    head = sort_biotonic(head, tail);

    printf("\nThe sorted list is : ");

    printDLL(head);
}
