#include <iostream>

using namespace std;

template<typename t>

class node
{
    public:
        t data;
        node<t> * left;
        node<t> * right;

        node(t d)
        {     
            data= d;
            left=NULL;
            right=NULL;                            

        }

};

int i=0;

void buildtree(int array[], node<int> *&root)
{
   if(array[i]==-1)
   {
       return;
   }
    node<int> * n= new node<int>(array[i]);
    
    root = n;
    
    i++;
    buildtree(array,root->left);
    i++;
    buildtree(array,root->right);
}

void printin(node<int> * tree)  // inorder
{
    if (tree==NULL)
    {
        return;
    }
    
    printin(tree->left);
    cout<<tree->data<<"  ";
    printin(tree->right); 

}
void printpost(node<int> * tree)  // post order
{
     if (tree==NULL)
    {
        return;
    }
    
    printpost(tree->left);
    printpost(tree->right); 
    cout<<tree->data<<"  ";

}
void printpre(node<int> * tree)  // preeorder
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
    int  array[19]={8,3,1,-1,-1,6,4,-1,-1,7,-1,-1,16,-1,14,13,-1,-1,-1};
    node<int> * tree;
    tree=NULL;
    buildtree(array,tree);
    cout<<"\npost   ";

    printpost(tree);
    cout<<"\npre    ";
    printpre(tree);
    cout<<"\nin     ";
    printin(tree);

    return 0;
}
