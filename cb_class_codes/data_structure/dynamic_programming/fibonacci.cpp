#include <iostream>
using namespace std;

int fibo(int n,int *arr)
{

    cout << " dfaoidsf  "<<arr[n];

    if (n==0 || n==1)
    {
        return n;   
    }
    if (arr[n]!=-1)
    {
        return arr[n];
    }
    return arr[n]=fibo(n-1,arr)+fibo(n-2,arr);
    
    
}
int main(int argc, char const *argv[])
{
    int n=5;
    int *arry=new int[n+1];

    for (int i = 0; i <= n; i++)
    {
        arry[i]=-1;
    }
    
    cout << "Fibonacci number of "<< n <<" is "<<fibo(n,arry);
    return 0;
}
