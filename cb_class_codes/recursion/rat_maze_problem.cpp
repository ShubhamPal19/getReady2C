// Find the path for the rat to get food.

//     rat  1   1   1    
//      1   1   0   0 
//      1   1   1   1
//      0   0   1   food
     

// 0 ---> open path:
// 1 --->blocked path;


// constraints : rat can only move from left to right and top to down;



#include<iostream>
#include<cstdlib>
using namespace std;


int *path;  //stores 1 for right, and 0 for down movement of rat;

void path_to_food(int a[], int i, int j,int k,int n,int m)
{
   if (i==n-1 && j==m-1)
   {
       for (int k = 0; k < n+m-2; k++)
       {
           if (path[k])
           {
               cout <<"Right->";
            
           }
           else
                    cout <<"Down->";
            
       }
       cout <<"food"<<endl;
       return ;  
   }



   //recursive case;

   if (a[i*m+j+1]==0 && j<m-1)
   {
        path[k]=1;
        path_to_food(a,i,j+1,k+1,n,m);

   }
   if(a[(i+1)*m +j]==0 && i<n-1)
   {
       path[k]=0;
       path_to_food(a,i+1,j,k+1,n,m);
   }


    
}


int main(){

    int *maze;
    int n,m,i,j;
    cout << "Enter the size of maze (rows,column) : ";
    cin>> n>>m;   //n--> no. of 

    maze= (int*)calloc(n*m,sizeof(int));
    path= (int*)calloc(n+m-2,sizeof(int));
    
    cout<<"Enter the postion where path is blocked (enter 0 0 to stop)"<<endl;
    cin>>i>>j;
    while (i>0 || j>0)
    {
        maze[i*m + j]=1;
        
        cin>>i>>j;
    }
    path_to_food(maze,0,0,0,n,m);


    
   

}
