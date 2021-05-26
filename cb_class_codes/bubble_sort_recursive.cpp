#include<iostream>

using namespace std;


void bubble_sort(int arr[],int n)
{
    if(n==0)
    {
        return ;
    }
    int flag =0;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
            flag=1;
        }
        
    }
    if (!flag)
    {
        return ;
    }
    bubble_sort(arr,n-1);



    
    
}
int main(){

    int arr[]={4,55,2,1,3,37,8,84};
    int n= sizeof(arr)/sizeof(int);

    bubble_sort(arr,n);

    for (int i = 0; i < n; i++)
    {
       cout << arr[i]<<" ";
    }
    

}