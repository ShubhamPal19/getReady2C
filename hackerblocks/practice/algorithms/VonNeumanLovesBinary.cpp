// Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 in binary is 7 in decimal.

// Input Format
// The first line contains N , the number of binary numbers. Next N lines contain N integers each representing binary represenation of number.

// Constraints
// N<=1000 Digits in binary representation is <=16.

// Output Format
// N lines,each containing a decimal equivalent of the binary number.

// Sample Input
// 4
// 101
// 1111
// 00110
// 111111
// Sample Output
// 5
// 15
// 6
// 63
// Explanation
// For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.

#include <iostream>
using namespace std;

int main()
{

    int n;

    cin >> n;

    long long *a = new long long[n];

    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    

    for (int i = 0; i < n; i++)
    {
        int place_multiplier = 1;
        long long sol = 0;
        while (a[i])
        {
            sol += a[i] % 10 * place_multiplier;
            place_multiplier *= 2;
            a[i] = a[i]/10;
        }
        cout<<sol<<endl;
    }
}
