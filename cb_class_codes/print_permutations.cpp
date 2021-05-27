#include <iostream>
#include <string.h>
using namespace std;

void print_permutations(char s[], int i)
{
    if (s[i] == '\0')
    {
        cout << s << endl;
        return;
    }
    int j = i;
    while (s[j] != '\0')
    {
        swap(s[i], s[j]);
        print_permutations(s, i + 1);
         swap(s[i], s[j]);  // nullify : back tracking;
        j++;
    }
} 

int main()
{

    char s[100];
    cout << "Enter string : ";
    cin >> s;
    print_permutations(s, 0);

    return 0;
}