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

void printfromto(node * root,int k1,int k2 )
{
    if (root == NULL)
    {
        return;
    }
    printfromto(root->left,k1,k2);

    if(root->data>k2)
        return;
    if (root->data>=k1 )
        cout<<root->data<<  "  ";
    
    printfromto(root->right,k1,k2);




    
    
}



int main()
{
    node *root = create_bst();


    // print ----> data present in bst in range k1 and k2;

    printfromto(root,8,19);

}


// 10 15 12 11 13 18 19 24 5 1 47 4 9 8 7 -1
