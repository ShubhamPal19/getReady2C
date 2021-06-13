#include <iostream>
using namespace std;

// you can perform N/3,N/2 and N-1; to get 1 from n. Now find the minimum number of steps required to get 1;


//top down approach

int minsteps(int n)
{
    if (n == 1)
        return 0;
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if (n % 3 == 0)
       op1= minsteps(n / 3) + 1;

    if (n % 2 == 0)
        op2= minsteps(n / 2) + 1;

     op3= minsteps(n - 1) + 1;

     return min(min(op1,op2),op3);
}

int main()
{   
    int n=10;

    cout<<"Minimum steps to 1 from "<< n<< " is "<< minsteps(n);
    return 0;
}