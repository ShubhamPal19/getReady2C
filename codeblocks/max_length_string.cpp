
#include<iostream>
#include<string.h>

using namespace std;
int lengthh(char s[100])
{
   int   l=0;
    while (s[l]!='\0')
    {
        l++;
    }
    return l;
}
int main()
{
    char  s[100],temp[100];

    int maxlen=0,clen,n;
    cout << "enter the number of string : ";

    cin>>n;
    cout<<"ENter the strings "<<endl;


    for (size_t i = 0; i < n; i++)
    {
        cin>>temp;

        clen=lengthh(temp);
        if (maxlen<clen)
        {
            maxlen=clen;
            for (size_t i = 0; i < clen; i++)
            {
               s[i]=temp[i];
            }
            
        }
        
    }

    cout<< "Max length is :  "<< maxlen<<endl;
    cout << s <<endl;
    




}