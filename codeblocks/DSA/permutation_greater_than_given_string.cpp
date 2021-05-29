


// sample input "cab"
// sample output "cba"


#include<iostream>
#include<string.h>

using namespace std;



void permutations(string s, int i,string test)
{

    if (s[i] =='\0')
    {

        if(s > test)
        {
            cout << s<<endl;

        }
        return true ;
    }


    for (int k = i; s[k]!='\0'; k++)
    {
        swap(s[i],s[k]);
        
        permutations(s,i+1,test);
        swap(s[i],s[k]);
        
    }
    
    

    






}


int main()
{
    string input;
    string test;


    cout <<"Enter the input string : ";
    cin>>input;
     
    permutations(input , 0, input);
}