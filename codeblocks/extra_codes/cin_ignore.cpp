#include<iostream>

using namespace std;

int main(){


    // char a[100];


    // int n;
    // // cin>>n;

    // // cin.getline(a,100);
    // // cout <<n<<endl;
    // // cout<<a;

    // cin>>n;
    // cin.ignore();    //  ignore '\n' after hitting enter for input of int n;

    // cin.getline(a,100);
    // cout <<n<<endl;
    // cout<<a;



    // cin.getline(a,100,'p');
    // cout <<a<<endl;





    char str[100];
    cin.getline(str,100);

    for (size_t i = 0; i < 100; i++)
    {
       cout<< str[i];
    
    }

    cout <<7474;

    string s;
    cin>>s;

    for (size_t i = 0; i < 100; i++)
    {
       cout<< s[i];
    
    }
   
    cout <<7474;
}