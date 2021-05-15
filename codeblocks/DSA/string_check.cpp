// WAP to check whether a string is a rotation of another string or not.

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str1, str2;
    cout << "Enter the first strings : " << endl;
    cin >> str1;
    cout << "Enter the second strings : " << endl;
    cin >> str2;

    int len1, len2, r;
    char temp;
    len1 = str1.length();
    len2 = str2.length();
    // l = 0;
    // r = len - 1;.

    if (len1 != len2)
    {
        cout << "\n The first string cannt be obtained by rotation of second string.";
        exit(0);
    }
    int j;

    for (size_t i = 0; i < len2; i++)
    {
        if (str1[0] == str2[i])
        {
            for (j = 1; j < len2; j++)
            {
                if (str1[j] == str2[(i + j) % len2])
                    continue;
                break;
            }

            if (j == len2)
            {
                cout << "\n The first string can be obtained by rotation of secong string." << endl;
                break;
            }
        }
    }
    if (j != len2)
    {
        cout << "\n The first string can not be obtained by rotation of secong string." << endl;
    }

    return 0;
}
