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
   
node * create_tree(int array[],int s, int e)
{

    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node * n= new node(array[mid]);
    n->right= create_tree(array,mid+1,e);
    n->left= create_tree(array,s,mid-1);
    return n;
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
    int array[]={1,2,3,4,5,6,7,8,9,11,12,13,14,15,17};
    node *root = create_tree(array,0,sizeof(array)/4-1);
    cout << "\npost   ";
    printpost(root);
    cout << "\npre    ";
    printpre(root);
    cout << "\nin     ";
    printin(root);

}