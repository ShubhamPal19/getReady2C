// Given N, help Manmohan to print pattern upto N lines. For eg For N=6 , following pattern will be printed.

// 1
// 11
// 111
// 1001
// 11111
// 100001

// Input Format
// Single number N.

// Constraints
// N<=1000

// Output Format
// Pattern corresponding to N.

// Sample Input
// 6
// Sample Output
// 1 
// 11
// 111 
// 1001 
// 11111
// 100001
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int sandwitch;

    if(n)
    cout<<1<<endl;

    for (int i = 2; i <= n; i++)
    {
        cout<<1;
        sandwitch=i%2;
        for (int j = 0; j < i-2; j++)
        {
            cout<<sandwitch;
           
        }
        
        cout<<1<<endl;
        
    }
    
}