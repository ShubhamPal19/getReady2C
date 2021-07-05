// Given a balanced binary tree find sum of all the nodes.

// Input Format
// First line contains N the number of elements in the tree. Next line contains N space separated elements.

// Constraints
// 0 <= N <= 10^6

// -10^7 <= tree.data <= 10^7

// Output Format
// A single integer : Sum of the tree

// Sample Input
// 3  
// 1 2 3  
// Sample Output
// 6

#include<iostream>
using namespace std;


class node
{
    public:
    long long int data;
    node * right,* left;

    node(long long int t)
    {
        data=t;
        right=left=NULL;
    }
    
};



// class bstree
// {
//     node * root;

//     public:

//     bstree(){
//         root=NULL;
//     }
    
//     void insert(long  long int data,node * root)
//     {
//         if ( data<=root->data)
//         {
//             if (root->left==NULL )
//             {
//                root->left =new node(data);

//             }
//             else
//               insert(data,root->left);
            
            
//         }
//       else 
//         {
//             if (root->right==NULL )
//             {
//                root->right =new node(data);
//             }
//             else
//               insert(data,root->right);
//         }
        
       

        
//     }
    
//     long long int sumNodes(node * root=root)
//     {
//         if (root==NULL)
//         {
//             return 0;
//         }
        
        
//         return root->data + sumNodes(root->right)+ sumNodes(root->left);

//     }

// };



    void insert(long  long int data,node * &root)
    {
        if (root==NULL)
        {
            root=new node(data);
            return ;
        }
        
        if ( data<=root->data)
        {
            if (root->left==NULL )
            {
               root->left =new node(data);

            }
            else
              insert(data,root->left);
            
            
        }
      else 
        {
            if (root->right==NULL )
            {
               root->right =new node(data);
            }
            else
              insert(data,root->right);
        }
        
       

        
    }
    
    long long int sumNodes(node * root)
    {
        if (root==NULL)
        {
            return 0;
        }
        
        
        return root->data + sumNodes(root->right)+ sumNodes(root->left);

    }

int main()
{

    long int n;
    cin>>n;
    node * root=NULL;
    long int data;
    for (long int i = 0; i < n; i++)
    {
        cin>>data;
        insert(data,root);
    }
    

    cout<< sumNodes(root);

}