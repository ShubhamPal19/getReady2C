


#include <iostream>


using namespace std;

int main()
{
    int n,ffn=0,sfn=1,temp;


    cout<<"\nEnter the key: ";
    cin>>n;

    if(n==ffn||n==sfn)
    {
        cout<<"\nThe given key is a fibonacci number.";
        return 0;
    }


    while(n>sfn)
    {
       sfn+=ffn;
       ffn=sfn-ffn;

       if(n==sfn)
       {
           cout<<"\nThe given key is a fibonacci number.";
           return 0;
       }
        
    }
    cout<<"\nThe given number is not a fibonacci number.";
    return 0;


}

