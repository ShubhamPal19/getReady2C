
// Replace each node with the sum of all greater nodes in a given BST

// Input Format
// Enter the number of nodes N and add N more numbers to the BST

// Constraints
// None

// Output Format
// Display the resulting tree

// Sample Input
// 3
// 2
// 1
// 3
// Sample Output
// 5 => 3 <= 0
// END => 5 <= END
// END => 0 <= END

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right, *parent;
};
int sum = 0;

void find_BST_sum(struct node *node)
{

    if (node == NULL)
    {
        return;
    }
    sum = sum + node->key;
    printf("\nbst node = %d ", node->key);
    find_BST_sum(node->left);
    find_BST_sum(node->right);
}

void replace_sum(struct node *node)
{

    if (node == NULL)
            return;
    
    replace_sum(node->left);
    sum -= node->key;
    node->key = sum;
    replace_sum(node->right);
}

void print_BST(struct node *node)
{

    if (node == NULL)
    {
        return;
    }

    if (node->right != NULL && node->left != NULL)
        printf("\n%d => %d <= %d", node->left->key, node->key, node->right->key);
    else if (node->left == NULL && node->right == NULL)
        printf("\nEND => %d <= ENd", node->key);
    else if (node->right == NULL)
        printf("\n%d => %d <= END", node->left->key, node->key);
    else
        printf("\nEND => %d <= %d", node->key, node->right->key);

    print_BST(node->left);
    print_BST(node->right);

    /*   this is alternative of above written code block */

    //     if (node->left != NULL && node->right != NULL)
    //     {
    //         printf("\n%d => %d <= %d", node->left->key, node->key, node->right->key);
    //         print_BST(node->left);
    //         print_BST(node->right);
    //     }

    //     else if (node->left == NULL && node->right==NULL)
    //     {
    //         printf("\nEND => %d <= ENd", node->key);

    //     }
    //     else if (node->right == NULL)
    //     {
    //         printf("\n%d => %d <= END", node->left->key, node->key);
    //         print_BST(node->left);
    //     }

    //     else
    // {printf("\nEND => %d <= %d", node->key, node->right->key);
    // print_BST(node->right);}
}
void insert(struct node **root, struct node *temp)
{

    if (*(root) == NULL)
    {
        (*root) = temp;
        (*root)->parent = NULL;
        return;
    }

    struct node *current;
    current = (*root);
    while (1)
    {
        if (temp->key < current->key)
        {
            if (current->left == NULL)
            {
                current->left = temp;
                temp->parent = current;
                return;
            }
            else
                current = current->left;
        }
        else
        {

            if (current->right == NULL)
            {
                current->right = temp;
                temp->parent = current;
                return;
            }
            else
                current = current->right;
        }
    }
}

void main()
{

    int n, i;

    struct node *root, *temp;
    root = NULL;

    printf("\nEnter the number of nodes in BST :");
    scanf("%d", &n);

    printf("\nEnter the key value of nodes : ");
    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &temp->key);
        temp->right = NULL;
        temp->left = NULL;
        insert(&root, temp);
    }

    find_BST_sum(root);
    replace_sum(root);
    print_BST(root);
}
