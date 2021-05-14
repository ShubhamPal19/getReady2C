#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str1;
    cin >> str1;
    int len, l, r;
    char temp;
    len = str1.length();
    l = 0;
    r = len - 1;

    while (l < r)
    {

        if (str1[l] == str1[r])
        {

            l++;
            r--;
        }
        else
        {
            cout << "The given string is not palindromic sequence." << endl;
            return 0;
        }
    }

    cout << "The given string is  palindromic sequence." << endl;
    return 0;
}