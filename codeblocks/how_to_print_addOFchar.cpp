#include <iostream>
#include <string>


using namespace std;

int main(){

    char ch;
    ch='a';

    cout << &ch<<endl;  //exception case , it will not give the address of ch;

    // cout << (int *)&ch <<endl;// fooling compiler.to get address of ch;



    char a[]={'d','a','g','q','q','q'};
    cout << &a<<endl;
    char b[]=" chaodif";
    cout <<b<<endl;


    string str = "";
    // cin >>str;
    // cout<<str<<endl;

   
    ch=cin.get();
    while(ch != '\n')
    {
        str.push_back(ch);
    }
    cout<<str;
}

  