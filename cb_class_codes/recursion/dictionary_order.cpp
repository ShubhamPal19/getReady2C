#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

string test_string_input;
void dictionaryorder(string in, string out)

{

    // base case

    if (in.length() == 0)
    {

        if (test_string_input < out)
        {
            cout << out << endl;
        }
    }

    // recursive case

    string temp_in;
    for (int i = 0; i < in.length(); i++)
    {
        temp_in = in.substr(0, i) + in.substr(i + 1);
        dictionaryorder(temp_in, out + in[i]);
    }
}

int main()
{
    string s;
    cout << "Enter the sting : ";
    cin >> s;
    test_string_input = s;
    sort(s.begin(), s.end());
    dictionaryorder(s, "");
}