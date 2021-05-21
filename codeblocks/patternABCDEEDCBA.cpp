// DRAW THE FOLLOWING PATTERN
// ABCDEEDCBA
// ABCDDCBA
// ABCCBA
// ABBA
// AA

#include <iostream>
using namespace std;

int main()
{

    int n, i;
    char ch = 'A' - 1;

    cout << "Enter the Number of rows" << endl;
    cin >> n;

    while (n--)
    {
        for (i = 0; i <= n; i++)
        {
            ch++;
            cout << ch;
        }

        for (i = 0; i <= n; i++)
        {
            cout << ch;
            ch--;
        }
        cout << endl;
    }
    return 0;
}
