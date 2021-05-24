// // use of multiline macro

// #include <stdio.h>
// #define p                             \
//     printf("this is transformation"); \
//     printf("\n next line");           \
//     printf("\nlast line ");           \
//     int x = 5;

// void main()
// {

//     p;

//     printf("\n%d", x);
    
//     x  =  (x++);
//     printf("\n%d",x);




//     int a, b;
//     a=10;
//     b=20;

//     a= b++;

//     printf("\n a = %d \n b = %d ",a,b);

    
// }



#include <iostream>
#include <algorithm>
using namespace std;

// void a(int a[],int n)
// {

//     for (size_t i = 0; i < n; i++)
//     {
//         /* code */
//     }
    
// }

// void incre(int &a){
//     a++;
// }
// int main(){ 
//     int x;
//     x=5;
//     int & s=x;
//     int *y;
//     y=&x;

//     cout << y<<"  "<<*y<<endl;


//     cout <<s<< "  " <<*(&s)<<endl;



//     x=10;
//     incre(x);
//     cout<<x<<endl;


//     int a[]={1,23,3};
//     cout<< *(a+4);


// }



// int main(){

//     int a[10]={1,2,32,3,3,323,32,3,33453};
//     sort(a,a+10);
//     for (size_t i = 0; i < 10; i++)
//     {
//     cout<<a[i]<<" ";
//         /* code */
//     }
    
// }


int main(){

    char a[]={'a','r','1','3'};
    char b[]={'q','e','y',','};
    cout<< a<<endl;
    cout <<b;

}