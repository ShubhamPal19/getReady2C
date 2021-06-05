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

int height(node<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->right), height(root->left)) + 1;
}

int diameter(node<int> *root)
{   

    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->right)+height(root->left),max(diameter(root->right),diameter(root->left)));
}

int main(int argc, char const *argv[])
{
    // int n;
    // n=19;
    // int * array=new int[n];
    int array[19] = {8, 3, 1, -1, -1, 6, 4, -1, -1, 7, -1, -1, 16, -1, 14, 13, -1, -1, -1};
    node<int> *tree;
    tree = NULL;
    buildtree(array, tree);
    cout << "height of btree is " << diameter(tree) << endl;
    return 0;
}
