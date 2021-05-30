#include <iostream>
using namespace std;

int main()
{
    int *ptr;

    ptr = new int;     //premitive data type memo allo;

    cout << "Enter value : ";

    cin >> *ptr;

    delete ptr;  // deleting premitive allocated memory;
    ptr = NULL;


    int * arr, n=4;

    arr= new int[n];
cout << "Enter the array"<<endl;
    for (size_t i = 0; i < 4; i++)
    {
        cin>> *(arr+i);
    }
    
    for (size_t i = 0; i < 4; i++)
    {
        cout << *(arr+i) <<"  ";
    }
    cout << endl;
    delete []arr;   //  deleting ar;

    arr=NULL;

    
}