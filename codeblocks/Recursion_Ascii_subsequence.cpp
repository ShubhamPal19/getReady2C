// Take as input str, a string. We are concerned with all the possible ascii-subsequences of str. E.g. “ab” has following ascii-subsequences “”, “b”, “98”, “a”, “ab”, “a98”, “97”, “97b”, “9798”

// a. Write a recursive function which returns the count of ascii-subsequences for a given string. Print the value returned.

// b. Write a recursive function which prints all possible ascii-subsequences for a given string (void is the return type for function).

// Input Format
// Enter the string

// Constraints
// None

// Output Format
// Display the number of ASCII-subsequences and display all the ASCII- subsequences

// Sample Input
// ab
// Sample Output
//  b 98 a ab a98 97 97b 9798

#include<iostream>
#include <string>
#include<sstream>

using namespace std;



void recursive_subsequence(string s, int l)
{


}


int main()
{
    cout<< "s" ;

    string str;
    cin >> str;
    int n=1002,l = str.length();
    recursive_subsequence(str,l);
    string s;
    stringstream ss;
    ss<<n;
    ss>>s;
    cout << s;


    return 0;
}