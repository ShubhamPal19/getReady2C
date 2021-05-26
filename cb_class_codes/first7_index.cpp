#include <iostream>
using namespace std;


int first7(int arr[],int n, int index)
{
    cout <<index<<endl;

    if(index==n)
    {
        return -1;
    }

    if(arr[index]==7)
    {
        return index;
    }
    return first7(arr,n,index+1);
}

int main(){
    int arr[]={1,4,5,2,3,44,7,89,8,0};
    int n= sizeof(arr)/sizeof(int);

   int index=0;
   index= first7(arr,n,0);
   cout << "Seven is present at index "<<index<<"."<<endl;
    

    
}