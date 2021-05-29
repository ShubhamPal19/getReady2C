#include <iostream>

using namespace std;

bool issorted(int a[],int n)
{
    if(n==1) 
    {
        return true;
    }

    return issorted(a,n-1)&&(a[n-1]>=a[n-2]);
    

}
int main()
{
    int n, array[100];

    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
   int  x=issorted(array ,n) ;

    x ? cout<<"Yes, array is sorted." : cout << "Array is not sorted.";
}
