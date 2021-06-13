#include <iostream>
using namespace std;

int d1=10,d2=7,d3=1;

//top down approach
int mindenomination(int n,int arr[])
{

    if (n==0)
        return  arr[n]=0;
    if (arr[n]!=-1)
        return arr[n];

    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    op3 = mindenomination(n-d3,arr);
    if (n-d1>=0)
    {
       op1= mindenomination(n-d1,arr);
    }
    if (n-d2>=0)
    {
       op2= mindenomination(n-d2,arr);
       }
       
          return arr[n];  
}



int main(int argc, char const *argv[])
{
    int n=15, *arr;
    arr=new int[n];
    for (int i = 0; i < n+1; i++)
    {
        arr[i]=-1;
    }
    
    cout<< "coin = "<< mindenomination(n,arr);
    return 0;
}
