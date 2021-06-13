#include <iostream>
using namespace std;

int fibo(int n)           //bottomup approach
{
    int *arry=new int[n+1];

    arry[0]=0;
    arry[1]=1;

for (int  i = 2; i <=n; i++)
{   
    arry[i]=arry[i-1]+arry[i-2];

}
cout<<endl;
for (int i = 0; i < n+1; i++)
{
    cout << arry[i]<< "  ";
}

cout<<endl;
    return arry[n];
    
    
}
int main(int argc, char const *argv[])
{
    int n=9;
    
    cout << "Fibonacci number of "<< n <<" is "<<fibo(n);
    
    return 0;
}
