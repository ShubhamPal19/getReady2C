// Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings ( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

// Input Format
// N(integer) followed by N strings.

// Constraints
// N<=1000

// Output Format
// N lines each containing one string.

// Sample Input
// 3
// bat
// apple
// batman
// Sample Output
// apple
// batman
// bat
// Explanation
// In mathematics, the lexicographic or lexicographical order (also known as lexical order, dictionary order, alphabetical order or lexicographic(al) product) is a generalization of the way words are alphabetically ordered based on the alphabetical order of their component letters.

#include <iostream>

#include <string>

using namespace std;

bool compar(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int i;
    for (i = 0; i < min(l1, l2); i++)
    {

    
        if (s1[i] ==s2[i])
        {
            continue;
        }

        if (s1[i] < s2[i])
        return true;
        else
        return false;
        
    }

    if(l1>l2)
    {

        return true;
    }
}

void sortstring(string *s[], int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
        {
            if (compar(*(s[j]),*(s[min]) ))
            {
                min=j;    
            }
            
        }

        swap(s[min],s[i]);
        
    }
}

int main()
{


    string *s[1000], *temp;
    int i, n;
    cin >> n;

    for (i = 0; i < n; i++)
    {

        temp = new string;
        cin >> *temp;
        s[i] = temp;
    }

    sortstring(s, n);
    for (i = 0; i < n; i++)
    {
        cout << *(s[i]) << endl;
    }

 

}