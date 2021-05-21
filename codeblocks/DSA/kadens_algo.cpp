//find the maximum sum of subarrays of a given array;
// kaden's algorith is not applicable on a  array with all negative elements


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int *array, max_sum=0,current_sum=0,i,n;
    cout<<"Enter the number of elements in an array : "<< endl;
    cin>> n;
    
    array = new int[n];
    cout<< "Enter the elements of array: ";
    for (size_t i = 0; i < n; i++)
    {
        cin>>*(array +i );
    }
    for (size_t i = 0; i < n; i++)
    {
        current_sum += *(array +i);
        if (current_sum<0)
        {
           current_sum=0;
        }
        max_sum=max(current_sum, max_sum);
        
    }
    cout <<"Maximum sum of subarray is : "<<max_sum<< endl;
   


}