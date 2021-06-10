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

node * deleteinbst(node * root, int key)
{
    node * temp;
    if (root->data>key)
    {
     root->left=   deleteinbst(root->left,key);
     return root;
    }
    

    if (root->data<key)
    {
     root->right=   deleteinbst(root->right,key);
      return root;
    }

    if (root->left==NULL)
    {
        temp=root->right;
        delete root;
        return temp;
    }

    if (root->right==NULL)
    {
        temp=root->left;
        delete root;
        return temp;
    }
     temp=root->right;
    while (temp->left!=NULL)
    {
        temp= temp->left;
    }
    swap(temp->data,root->data);
    root->right=deleteinbst(root->right,temp->data);
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


   root= deleteinbst(root,10);
   root =  deleteinbst(root,8);
   root=deleteinbst(root,1);

   cout<<"\ntree after deletion of 3 nodes is :"<<endl;

    cout << "\npost   ";
    printpost(root);
    cout << "\npre    ";
    printpre(root);
    cout << "\nin     ";
    printin(root);

}

// 8 3 1 6 4 10 5 7 12 10 16 14 13 5 1 15 18 -1