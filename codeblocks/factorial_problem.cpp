// Mike found an interesting problem. In this problem you are given two integers, n and k.
//  You need to find the the maximum value of x, such that, n! % kx = 0.

// Input Format
// First line contains number of test cases, T. Each test case contains two integers each, n and k.

// Constraints
// 1<=T<=20 1<=n<=10^8 2<=k<=10^8

// Output Format
// Print the value of x for each test case.

// Sample Input
// 1
// 5 2
// Sample Output
// 3

#include<iostream>
using namespace std;

int factorial(int n)
{   
    if (n==1)
     return 1;
    return  n*factorial(n-1);
}

int find_x(int n, int k )
{
    int x,i=0,fact,pow_k=1;
    
    fact=factorial(n);
    while(pow_k<=fact)
    {
        if(fact%pow_k==0)
            x=i;
        i++;
        pow_k*=k;
    }
    return x;

}
int main()
{
    int * n, *k, *x,t;
    cout<<"Enter the test cases : ";
    cin>>t;
    n= new int[t];
    k=new int[t];
    x=new int[t];
    for (size_t i = 0; i < t; i++)
    {
        cout<<"Enter the value of n and k : "<<endl;
        cin>>n[i]>>k[i];
    }

    for (size_t i = 0; i < t; i++)
    {
      
      cout<<find_x(*(n+i),*(k+i));
    }
    

    


    
}
