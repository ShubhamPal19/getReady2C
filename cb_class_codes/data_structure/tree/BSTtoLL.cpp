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



node * head=NULL,* temp=NULL;

 void BSTtoLL(node * root)
 {
   
    if(root==NULL){
        flag=1;
         return;
    }
    
    BSTtoLL(root->right);
   
    root->right=temp;
    head=root;
    temp=root;
    BSTtoLL(root->left);
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




void printll(node *head)
{
    cout <<endl;

    while (head != NULL)
    {
        cout << head->data << " ";

        head = head->right;
    }

    cout << endl;
}

int main()
{
    node *root = create_bst();
    cout << "\npost   ";

    printpost(root);
    cout << "\npre    ";
    printpre(root);
    cout << "\nin     "s;
    printin(root);



    BSTtoLL(root);

    printll(head);
}


//  8 3 1 6 4 10 5 7 12 10 16 14 13 5 1 15 18 -1