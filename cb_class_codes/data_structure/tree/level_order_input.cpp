#include <iostream>
#include <queue>
using namespace std;

class node
{
public:

    int data;
    node * right, * left;

    node(int d )
    {
        data=d;
        right=NULL;
        left=NULL;


    }

};





node * buildtree_level()
{

     cout << "enter the root element "<<endl;
    int key;
    cin>> key;

    if (key==-1)
    {
        return NULL;
    }
    node * root=new node(key);

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node * x =q.front();
       q.pop();
        cout<<"Enter the data of children of "<< x->data<<endl;
        int lchild,rchild;
        cin>>lchild>>rchild;
        if (lchild!=-1)
        {
         x->left=  new node(lchild);
         q.push(x->left);
        }
        
        if (rchild!=-1)
        {
         x->right=  new node(rchild);
         q.push(x->right);
        }

        
    }
    
    return root;




    

}

void printin(node * tree)  // inorder
{
    if (tree==NULL)
    {
        return;
    }
    
    printin(tree->left);
    cout<<tree->data<<"  ";
    printin(tree->right); 

}
void printpost(node * tree)  // post order
{
     if (tree==NULL)
    {
        return;
    }
    
    printpost(tree->left);
    printpost(tree->right); 
    cout<<tree->data<<"  ";

}
void printpre(node* tree)  // preeorder
{
     if (tree==NULL)
    {
        return;
    }
    
    cout<<tree->data<<"  ";
    printpre(tree->left);
    printpre(tree->right); 

}


int main(int argc, char const *argv[])
{
    // int n;
    // n=19;
    // int * array=new int[n];
    


    node * root;
   
    root =buildtree_level();
    cout<<"\npost   ";

    printpost(root);
    cout<<"\npre    ";
    printpre(root);
    cout<<"\nin     ";
    printin(root);

    return 0;
}

  //                                   1
//                               3            2
//                             8    9         7   4
//                            1       3
//                         11          
//                         12          
//                        13           
//                     1       2
//                            3    4




