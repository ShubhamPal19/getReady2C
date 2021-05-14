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
        temp = str1[l];
        str1[l] = str1[r];
        str1[r] = temp;
        l++;
        r--;
    }

    cout << str1 << endl;
    return 0;
}