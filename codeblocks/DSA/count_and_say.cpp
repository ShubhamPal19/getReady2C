

// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string count_and_say(int n)
{
    if (n == 1)
        return "1";

    string str1, str2 = "";
    char ch;
    str1 = count_and_say(n - 1);
    int len = str1.length(), count, i = 0;
    while (i < len)
    {
        ch = str1[i];
        count = 1;
        while (ch == str1[++i])
            count++;
        str2 += '0' + count;
        str2 += ch;
    }
    return str2;
}

int main()
{
    int n;
    cout << "Enter the value of n : " << endl;
    cin >> n;

    string s;
    s = count_and_say(n);
    cout << s << endl;
}