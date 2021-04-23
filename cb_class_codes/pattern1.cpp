// Print the following pattern

// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1s
// 0 1 0 1 0 1

#include <iostream>

using namespace std;

int main()
{
    int n, i,j, element=1;
    cout<<"Enter the number of line in pattern: ";
    cin>>n;
    for ( i = 1; i <= n; i++)
    {
        element=i%2;
        for (j = 0; j < i; j++)
        {
            cout<<element<< " ";
            element=(element+1)%2;

        }
        cout<<"\n";
        
    }

    return 0;
    
}




