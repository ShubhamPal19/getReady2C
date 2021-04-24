// Implement Insertion Sort in a linked list using recursion.

// Base Case: If array size is 1 or smaller, return.
// Recursively sort first n-1 elements.
// Insert last element at its correct position in sorted array.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next, *previous;
};

void printlist(struct node *head)
{
    struct node *current;
    current = head;
    while (current != NULL)
    {
        printf("%d  ", current->key);
        current = current->next;
    }
}

void insert_node(struct node **head, struct node *tail)
{
    struct node *current, temp;
    int flag;
    flag = 0;
    if (tail->key >= tail->previous->key)
    {
        return;
    }

    current = tail->previous;

    while (current->key >= tail->key)
    {
        if (current->previous == NULL)
        {
            flag = 1;
            break;
        }
        current = current->previous;
    }

    tail->previous->next = tail->next;
    if (tail->next != NULL)
        tail->next->previous = tail->previous;

    if (flag)
    {

        current->previous = tail;
        tail->previous = NULL;
        tail->next = current;
        (*head) = tail;
        return;
    }

    tail->next = current->next;
    current->next->previous = tail;
    tail->previous = current;
    current->next = tail;
}

void recursive_insertion_sort(struct node **head, struct node *tail)
{

    if ((*head) == (tail))
    {
        return;
    }

    recursive_insertion_sort(head, tail->previous);

    insert_node(head, tail);
}

void add_node(struct node **head, struct node **tail, int key)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->previous = NULL;
    temp->key = key;
    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        temp->previous = (*tail);
        (*tail) = temp;
    }
}

void main()
{

    struct node *head, *tail, *temp;

    head = NULL;
    tail = NULL;

    int n, i, key;

    printf("Enter the number of elements in link list : ");
    scanf("%d", &n);

    printf("Enter the data : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        add_node(&head, &tail, key);
    }
    printf("\nThe given list is :\n");
    printlist(head);
    recursive_insertion_sort(&head, tail);
    printf("\nThe sorted list is :\n");
    printlist(head);
}