#include<iostream>

using namespace std;

int main()

{
    int x,y;
    x=10;
    y=20;
    cout<< "The value of x is : "<<x<<"  and the value of y is : "<<y<<endl;

    //swap using temp
    int temp;
    temp=x;
    x=y;
    y=temp;
    cout<< "The value of x is : "<<x<<"  and the value of y is : "<<y<<endl;



    //one lline swapping

    y=x+y-(x=y);
    cout<< "The value of x is : "<<x<<"  and the value of y is : "<<y<<endl;


    // swapping without temp;
    x=x+y;
    y=x-y;
    x=x-y;
    cout<< "The value of x is : "<<x<<"  and the value of y is : "<<y<<endl;

    return 0;
}




