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

node *insert_bst(node *root, int data)
{
    if (root == NULL)
    {
        node *n = new node(data);
        return n;
    }
    if (data <= root->data)
        root->left = insert_bst(root->left, data);
    else
        root->right = insert_bst(root->right, data);

    return root;
}

node *create_bst()
{
    node *root = NULL;
    int data;
    cout << "Enter the data( -1 to stop) : ";
    cin >> data;
    while (data != -1)
    {
       root= insert_bst(root, data);
        cin >> data;
    }
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
    node *root = create_bst();
    cout << "\npost   ";

    printpost(root);
    cout << "\npre    ";
    printpre(root);
    cout << "\nin     ";
    printin(root);
}
