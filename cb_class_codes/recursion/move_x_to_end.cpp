#include <iostream>
#include <string.h>
using namespace std;

string move_x_to_end(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    string temp = s.substr(0, 1);
    s = move_x_to_end(s.substr(1));
    // (temp=="x")? return s+temp : return temp+s;
    if (temp == "x")
      return s + temp;
    else
        return  temp + s;

}

int main()
{

    string s;
    cout << "Enter string : ";
    cin >> s;
    s = move_x_to_end(s);
    cout << "string after moving x to end positions is \"" << s << "\"." << endl;
    return 0;
}