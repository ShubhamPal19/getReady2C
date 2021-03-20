// Given three linked lists, say a, b and c, find one node from each list such that the sum of
// the values of the nodes is equal to a given number say, Target. As any number of answers can
//  be possible return the first one you get while traversing.
// Input Format
// The First Line contains 3 Integers n, m and k as the Size of the Three LinedLists.
//  Next 3 Lines contains n, m and k integers Respectively as the elements of Linked Lists.
// Next Line contains the an Integer as Target.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
};

void input(struct node **temp)
{
    *temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &(*temp)->key);
    (*temp)->next = NULL;
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

    (*tailref)->next = temp;
    (*tailref) = temp;
}

void target_sum(struct node *head1, struct node *head2, struct node *head3, int target)
{
    struct node *current1, *current2, *current3;
    current3 = head3;

    while (current3 != NULL)
    {
        current2 = head2;
        while (current2 != NULL)
        {

            current1 = head1;
            while (current1 != NULL)
            {

                if (((current1->key) + (current2->key) + (current3->key)) == target)
                {
                    printf("\n %d %d %d ", current1->key, current2->key, current3->key);
                    return;
                }
                current1 = current1->next;
            }
            current2 = current2->next;
        }

        current3 = current3->next;
    }

    printf("\nThere is no sequence whose sum is equal to the target sum.");
}

void main()
{

    int i, n[3], target;
    struct node *head[3], *tail[3], *temp;
    head[0] = NULL;
    tail[0] = NULL;
    head[1] = NULL;
    tail[1] = NULL;
    head[2] = NULL;
    tail[2] = NULL;

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter the number of elements in link list %d : ", i + 1);
        scanf("%d", &n[i]);
        printf("\nEnter the data : ");
        while (n[i] != 0)
        {

            input(&temp);
            insert(&head[i], &tail[i], temp);
            n[i]--;
        }
    }
    temp = head[1];

    while (temp != NULL)
    {
        printf("   %d", temp->key);
        temp = temp->next;
    }

    printf("\nEnter the Target sum : ");
    scanf("%d", &target);
    target_sum(head[0], head[1], head[2], target);
    printf("\n");
}