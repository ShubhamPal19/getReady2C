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

class variables
{
    public:
     int height;
     int dia;

};




variables diameter(node<int> * tree)
{
     variables v;

    if (tree==NULL)
    {
       
        v.dia=0;
        v.height=0;
        return v ;
    }
    variables left=diameter(tree->left);
    variables right=diameter(tree->right);
   v.height=max(left.height,right.height)+1;
   v.dia=max(max(left.dia,right.dia),left.height+right.height);

   return v;

    

    


}





// int height(node<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     return max(height(root->right), height(root->left)) + 1;
// }

// void diameter(node<int> *root , int &diameter )
// {

//     if (root == NULL)
//     {
//         return 0;
//     }

//     return max(height(root->right) + height(root->left), max(diameter(root->right), diameter(root->left)));
// }
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
    // int n;
    // n=19;
    // int * array=new int[n];
    int array[] = {1, 3, 8, 1, 11, 12, 13, 1, -1, -1, 2, 3, -1, -1, 4, -1, -1, -1, -1, -1, -1, 9, -1, 3, -1, 2, -1, 1, 19, -1, -1, 14, -1, -1,
                   2, 7, -1, -1, 4, -1, -1};

    int array2[] = {1, 3, 8, 1, 11, 12, 13, 1, -1, -1, 2, 3, -1, -1, 4, -1, -1, -1, -1, -1, -1, 9, -1, 3, -1, -1,
        2, 7, -1, -1, 4, -1, -1};
node<int> *tree;
tree = NULL;

buildtree(array, tree);
cout << "\npost   ";
printpost(tree);
cout << "\npre    ";
printpre(tree);
cout << "\nin     ";
printin(tree);

cout << "\nDIAMETER of btree is " << diameter(tree).dia  << endl;

tree = NULL;
i=0;
buildtree(array2, tree);
cout << "\npost   ";
printpost(tree);
cout << "\npre    ";
printpre(tree);
cout << "\nin     ";
printin(tree);

cout << "\nDIAMETER of btree is " << diameter(tree).dia << endl;
return 0;
}

//                                     1
//                               3            2
//                             8    9         7   4
//                            1       3
//                         11           2
//                         12             1
//                        13           19   14
//                     1       2
//                            3    4

// 1,3,8,1,11,12,13,1,-1,-1,2,3,-1,-1,4,-1,-1,-1,-1,-1,-1,9,-1,3,-1,2,-1,1,19,-1,-1,14,-1,-1,
// 2,7,-1,-1,4,-1,-1}

//                                     1
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