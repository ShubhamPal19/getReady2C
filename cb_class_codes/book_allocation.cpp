#include <iostream>

using namespace std;


bool isvalid(int a[], int n, int m,int capacity)
{
    int s=1;
    int currentpages=0;

    for (int i = 0; i < n; i++)
    {
        if (currentpages+ a[i] >capacity)
        {
            s++;
            currentpages=a[i];
            if (s>m)
            {
                return false;
            }
            
            
        }
        else
        {
            currentpages += a[i];
        }
        
    }

   return true;
    
}
int book_all(int arr[],int n , int m)
{

    int totalpages=0;
    int s,e;
    for (int i = 0; i < n ; i++)
    {
        totalpages += arr[i];
        
    }
    s=arr[n-1];
    e=totalpages;
int finalans=0;
    while (s<=e)    
    {
        int mid=(s+e)/2;
        if(isvalid(arr,n,m,mid)){
        finalans=mid;
            e=mid-1;

        }
        else
        {
            s=mid+1;

        }
        
    }
return finalans; 
    
     
}

int main(){
     
     int t, n,m,arr[1000]; //n->number of books, m->students

     cin>>t;
     while (t--)
     {
        
        cin>>n>>m;

        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        int x= book_all(arr,n,m); 
         cout <<x<<endl; 

     }

  
     




}