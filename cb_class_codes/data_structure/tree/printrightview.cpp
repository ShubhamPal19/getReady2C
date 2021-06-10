#include <iostream>
#include <queue>

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

int currentlevel=-1;

void rightview(node * root , int level)
{

    if (root==NULL)
    {
        return;
    }
    
    if (currentlevel==level-1)
    {
        cout << root->data<< "  ";
        currentlevel=level;
    }
    

    rightview(root->right,level+1);
    rightview(root->left,level+1);
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



void level_order(node * root)
{


    queue<node *> level;
    level.push(root);
    level.push(NULL);
  
    node * x=level.front();
   while (1)
    {
        x=level.front();
       if (x==NULL)
       {
           cout <<endl;
           level.pop();
           if (level.empty())
           {
               break;
           }
           
           level.push(NULL);
       }
       else{
          if (x->left !=NULL)
          {
           level.push(x->left);
          }
          if (x->right !=NULL)
          {
           level.push(x->right);
          }
          
          
           cout<<x->data<<"  ";
           level.pop();

       }
       
    }

    cout <<endl;
    



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


    cout<<endl<<"Right view of the tree is : ";

     rightview(root,0);

    cout <<endl;
    level_order(root);


}

// 8 3 1 6 4 10 5 7 12 10 16 14 13 5 1 15 18 -1


                //                     8
                //          3           
                // 1               6
