// WAP to check whether a string is a valid shuffle of two strings or not .

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str1, str2, result;
    cout << "Enter the first strings : " << endl;
    cin >> str1;
    cout << "Enter the second strings : " << endl;
    cin >> str2;
    cout << "Enter the shuffled result : " << endl;
    cin >> result;

    int len1, len2, len3,i,j,k;
    len1 = str1.length();
    len2 = str2.length();
    len3 = result.length();

    if (len1+len2 != len3 )
    {
      cout<< "The \"" << result <<"\" is not a valid shuffle of \""<<str1<< "\" and \"" << str2 << "\". " << endl;
      return 0;
    }
    
    j=0;
    k=0;

    for ( i = 0; i < len3  ; i++)
    {
        if(result[i]==str1[j])
            j++;
        else if (result[i]==str2[k])
            k++;
        else
            {
                cout<< "The \"" << result <<"\" is not a valid shuffle of \""<<str1<< "\" and \"" << str2 << "\". " << endl;
                break;
            }
    }

    if (j+k == len3)
    {
        cout<< "The \"" << result <<"\" is  a valid shuffle of \""<<str1<< "\" and \"" << str2 << "\". " << endl;

    }
    
    return 0;

}    