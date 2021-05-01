// Aisha and Ayush were playing word games. They both wrote two words randomly.
//Now you have to check if one word can be formed by jumbling the letters of another word. If possible, then print "True", otherwise print "False".

// Input Format
// First line contains word written by Aisha and second line contains word written by Ayush.

// Constraints
// You may assume the string contains only lowercase alphabets.

// Output Format
// Print True, if possible, else print False.

// Sample Input
// hello
// holle
// Sample Output
// True
// Explanation
// Second string "holle` can be arranged to form "holle".

#include <iostream>
#include <string.h>

#include <stdlib.h>

using namespace std;

int main()
{
    string w1, w2;
    cout << "Enter the first word : ";

    cin >> w1;
    cout << "Enter the second word : ";
    cin >> w2;

 

    int *flag,tag ,l1, l2;

    l1 = w2.length();
    l2 = w2.length();
    if (l1 != l2)
    {
        cout << "\nFALSE\n";
        exit(0);
    }
    flag = (int *)calloc(l2, 4);

    int i = 0, j;
    char ch;

    for (i = 0; i < l2; i++)
    {
        tag = 0;
        for (j = 0; j < l1; j++)
        {
            if (w1[i]==w2[j]&& *(flag+j)==0)
            {
                *(flag+j)=1;
                tag=1;
                break;
            }
        }

        if (!tag)

        {
            cout<<"\nFALSE\n";
            exit(0);
        }
    }

    cout<<"\nTRUE";
}
