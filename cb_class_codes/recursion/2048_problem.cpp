#include <iostream>
using namespace std;

string decimal_to_word[10] = {"Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};

string convert_to_words(int n, string s){
    if (n == 0)
        return s;
    int unitplace = n % 10;
    s = convert_to_words(n / 10, s);
    return s + decimal_to_word[unitplace];
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    string word_string = "";
    word_string = convert_to_words(n, word_string);
    cout << "decimal to word of " << n << " is \"" << word_string << "\"." << endl;
}