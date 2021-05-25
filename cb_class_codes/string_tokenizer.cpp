#include <iostream>
#include <string.h>
using namespace std;
int main()
{

    char arr[] = "1234''''56$fasdhfkj,,,dfids";

    char *ptr;

    ptr = strtok(arr, "$,'");    //strtok  will not maintain the original string;
//   char ch=arr[0];
//   int i=1;
//     while (i!=30)
//     {
//         cout<< ch;
//         ch = arr[i++];

//     }
    
        // cout << ptr << endl;
        // cout << arr << endl;

    while (ptr != NULL)
    {
        cout << ptr << endl;
        cout<<(int *) ptr<<"  "<<(int *)arr << endl;
        ptr = strtok(NULL, "$,'");
    }

   




    string s, s1("this is attribute to s1 object of class string"); // class string and object s;

    cout<<"Enter string : ";
    getline(cin,s);

    cout<<s<<endl;
    cout<<s1<<endl;

     s= s+s1;
    cout << s<< endl;

    string s2 = s+s1; 


    string s4="ABCD",s5="G";   // "G" > "ABCD"
    cout<<( s4>s5)<< endl;    //output 0;
    
    s4="YOU can PRactice here ";
    cout << s4.substr(5,15)<< endl;  //"an PRactice her" output.



}