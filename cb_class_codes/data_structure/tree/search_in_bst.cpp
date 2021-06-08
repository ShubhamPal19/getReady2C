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

bool searchinbst(node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    if (key < root->data)
         return searchinbst(root->left, key);
    return searchinbst(root->right, key);
}

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
        root = insert_bst(root, data);
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

    int key;
    cout << " Enter the key which you want to search for  : ";

    cin >> key;

    searchinbst(root, key) ? cout << "The key is present in bst." : cout << " key is not present in BST.";
}

// 10 15 12 11 13 18 19 24 5 1 47 4 9 8 7 -1
