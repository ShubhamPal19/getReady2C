// For the coding blocks placement test , kartik bhaiya decided to give students an array arr of n integers and an integer target. The task is to return the sum of three integers in arr such that their sum is closest to target.
// Assume that each input would have exactly one solution.

// Input Format
// First line contains integer n as size of array. Second line contains the target .Next n lines contains a single integer as element of array.

// Constraints
// None

// Output Format
// Print the sum that is closest to the target.

// Sample Input
// 4
// 1
// -1 
// 2 
// 1 
// 4
// Sample Output
// 2
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int * a= new int[n],target;
    cin >>target;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

   
    // int sol = a[0]+a[1]+a[2];

    // for (size_t i = 0; i < n-2; i++)
    // {
    //   for (size_t j = i+1; j < n-1; j++)
    //   {
    //      for (size_t k = j+2; k < n; k++)
    //      {
    //          if (abs(a[i]+a[j]+a[k]-target)<sol)
    //          {
    //              sol=a[i]+a[j]+a[k];
    //          }
             
    //      }
    //   }
        
    // }
    
    // function to sort ary
    for (int i = 0; i < n; i++)
    {
        int min_indx=i,j;
        for ( j = i+1; j < n; j++)
        {
            if (a[min_indx]>a[j])
        {
            min_indx=j;
        }
        
            
        }
        swap(a[i],a[min_indx]);
    }
    int sum=0;
    int sol=INT_MAX,j,k;
    for (size_t i = 0; i < n-1; i++)
    {
        
        
        j=i+1;
        k=n-1;
        while(j<k)
        {
            sum=a[i]+a[j]+a[k];
            if (abs(sum-target) < sol)
            {
                sol=sum-target;
            }
            
            
            if (sum>target)
        
             k--;
            
            else
            j++;
            
        }
        

    }
    
     
    


    
    cout<< sol+target<<endl;
    return 0;
}