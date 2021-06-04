#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isbalanced(string x)
{
    stack<char> s;
    
    char c ;
    for (int i = 0; x[i] != '\0'; i++)
    {
        c=x[i];
        switch (c)
        {
        case '(':
        case '{':
        case '[':  s.push(c);
                   break;
        case ')':
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
                return false;
            break;
        case ']':
            if (!s.empty() && s.top() == '[')
            {
                s.pop();
            }
            else
                return false;

            break;
        case '}':
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
                return false;
        }

    }
   
    if (s.empty())
    {
        return true;
    }

    else

        return false;
}

int main()
{
    string input;

    cout << "Enter the expression : ";

    cin >> input;

    if (isbalanced(input))
        cout << "Yes, Exppression is balanced." << endl;

    else
        cout << "Expression is not balanced." << endl;
}