#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};
int n;
int k = 0;

node *buildtree(int pre[], int in[], int i, int j)
{
    int c = i;
    while (in[c] != pre[k])
        c++;
 
    node *root = new node(pre[k++]);
    if (c != i)
        root->left = buildtree(pre, in, i, c - 1);
    if (c != j)
        root->right = buildtree(pre, in, c + 1, j);
    return root;
}

void printin(node *tree) // inorder
{
    if (tree == NULL)
    {
        return;
    }

    printin(tree->left);
    cout << tree->data << "  ";
    printin(tree->right);
}
void printpost(node *tree) // post order
{
    if (tree == NULL)
    {
        return;
    }

    printpost(tree->left);
    printpost(tree->right);
    cout << tree->data << "  ";
}
void printpre(node *tree) // preeorder
{
    if (tree == NULL)
    {
        return;
    }

    cout << tree->data << "  ";
    printpre(tree->left);
    printpre(tree->right);
}

int main()
{

    cout << "Enter the number of nodes in tree : ";
    cin >> n;

    int *pre = NULL, *in = NULL;

    pre = new int[n];
    in = new int[n];
    cout << "ENter the preorder representation of tree : ";
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    cout << "ENter the inorder representation of tree : ";
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    node *root = buildtree(pre, in, 0, n - 1);

    cout << "\npost   ";

    printpost(root);
    cout << "\npre    ";
    printpre(root);
    cout << "\nin     ";
    printin(root);
}

// 8  3  1  6  4  7  16  14  13

// 1  3  4  6  7  8  16  13  14