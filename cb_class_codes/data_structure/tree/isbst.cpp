#include <iostream>

     using namespace std;

template <typename t>

class node
{
public:
    t data;
    node<t> *left;
    node<t> *right;

    node(t d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

int i = 0;
void buildtree(int array[], node<int> *&root)
{
    if (array[i] == -1)
    {
        return;
    }
    node<int> *n = new node<int>(array[i]);

    root = n;

    i++;
    buildtree(array, root->left);
    i++;
    buildtree(array, root->right);
}

bool isBST(node<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }

    if ((root->data >= min && root->data <= max) && isBST(root->left, min, root->data) && isBST(root->right, root->data, max))
    {
        return true;
    }

    return false;
}

void printin(node<int> *tree) // inorder
{
    if (tree == NULL)
    {
        return;
    }

    printin(tree->left);
    cout << tree->data << "  ";
    printin(tree->right);
}
void printpost(node<int> *tree) // post order
{
    if (tree == NULL)
    {
        return;
    }

    printpost(tree->left);
    printpost(tree->right);
    cout << tree->data << "  ";
}
void printpre(node<int> *tree) // preeorder
{
    if (tree == NULL)
    {
        return;
    }

    cout << tree->data << "  ";
    printpre(tree->left);
    printpre(tree->right);
}

int main(int argc, char const *argv[])
{

    int array[19] = {8, 3, 1, -1, -1, 6, 4, -1, -1, 7, -1, -1, 16, -1, 14, 13, -1, -1, -1};
    node<int> *tree;
    tree = NULL;
    buildtree(array, tree);
    cout << "\npost   ";

    printpost(tree);
    cout << "\npre    ";
    printpre(tree);
    cout << "\nin     ";
    printin(tree);

    isBST(tree) ? cout << " \ntree 1 is  bst " << endl : cout << "\ntree 1 is not BST " << endl;



     i=0;
    int array2[19] = {8, 3, 1, -1, -1, 6, 4, -1, -1, 7, -1, -1, 16, -1, 19, 18, -1, -1, -1};
    node<int> *tree2;
    tree2 = NULL;
    buildtree(array2, tree2);
    cout << "\npost   ";

    printpost(tree2);
    cout << "\npre    ";
    printpre(tree2);
    cout << "\nin     ";
    printin(tree2);

    isBST(tree2) ? cout << " \ntree 2 is  bst " << endl : cout << "\ntree 2 is not BST " << endl;

    return 0;
}
