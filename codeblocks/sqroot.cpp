//  find the sq root of a number upto p decimal place.


#include<iostream>

using namespace std;


int main()
{

    float num, incr, root;
    int p,i;
    cout << "Enter the number : "<< endl; 
    cin>>num;
    cout << "Enter the decimal place upto which you want to calculate the square root : "<< endl;

    cin >> p;
    incr=10;
    root = -1;
    for ( i = 0; i <= p; i++){
        incr= incr/10;
        while ((root+incr)*(root+incr)<= num)
            root+= incr;    
    }

    cout << " the square root of the num is : "<< root<< endl;
    

}