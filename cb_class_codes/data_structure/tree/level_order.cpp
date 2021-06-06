
#include <iostream>
#include <queue>

using namespace std;

template <typename t>
class node
{
public:
    node<t> *left,* right;
    t data;

    node(t d)
    {

        left = NULL;
       
        right=NULL;
        data = d;
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



void level_order(node<int> * root)
{

    queue<node<int> *> level;

    cout << "her"<<endl;
    level.push(root);
    level.push(NULL);
    cout<<level.empty();
    node<int> * x=level.front();

    cout << x->data<<endl;

    
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
int main()
{
    int array[] = {1, 3, 8, 1, 11, 12, 13, 1, -1, -1, 2, 3, -1, -1, 4, -1, -1, -1, -1, -1, -1, 9, -1, 3, -1, -1,
                   2, 7, -1, -1, 4, -1, -1};
    node<int> *tree;
    tree = NULL;
    buildtree(array, tree);
    printin(tree);
    level_order(tree);
    


    
}






                            //  1
//                               3            2
//                             8    9         7   4
//                            1       3
//                         11          
//                         12          
//                        13           
//                     1       2
//                            3    4

// 1,3,8,1,11,12,13,1,-1,-1,2,3,-1,-1,4,-1,-1,-1,-1,-1,-1,9,-1,3,-1,-1,
// 2,7,-1,-1,4,-1,-1}