// Write a program for swaping cases in a string S. For swap case necessary conditions are:-

// Remove spaces and any special character
// Remove digits
// Convert uppercase to lowercase and vice versa
// Input Format
// The first line contains a string S.

// Constraints
// Output Format
// Display a single line output of the resulting string after swapping cases.

// Sample Input
// There are 206 bones
// Sample Output
// tHEREAREBONES

#include <iostream>
#include <string>
using namespace std;

string swap_case(string str)
{
  string s = "";
  char ch;
  int i, l;
  l = str.length();
  for (i = 0; i < l; i++)
  {
    ch = str[i];
    if (ch >= 'a' && ch <= 'z')
      ch = ch - 32;
    else if (ch >= 'A' && ch <= 'Z')
      ch = ch + 32;
    else
      continue;
    s.push_back(ch);
  }
 
  return s;
}

int main()
{

  string str;
  cout << "\nEnter the string : ";
  getline(cin, str);
  cout << str<<endl;
  str = swap_case(str);
  cout << str<<endl;
}
