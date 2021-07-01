// Andrew was attempting a mathematics test where he needed to solve problems with factorials. One such problem had an answer which equaled 100! ,He wondered what would this number look like. He tried to calculate 100! On his scientific calculator but failed to get a correct answer. Can you write a code to help Andrew calculate factorials of such large numbers?

// Input Format
// a single lined integer N

// Constraints
// 1 < = N < = 500

// Output Format
// Print the factorial of N

// Sample Input
// 5
// Sample Output
// 120
// Explanation
// for factorial of 5 we have 5 x 4 x 3 x 2 x 1 = 120

#include <iostream>

using namespace std;

int r_size = 1;

void multiply(int r[], int n)
{

    int carry = 0;
    int i, result;
    for (i = 0; i < r_size; i++)
    {
        result = r[i] * n + carry;
        r[i] = result % 10;
        carry = result / 10;
    }

    while (carry)
    {
        r[i] = carry % 10;
        carry = carry / 10;
        r_size = r_size + 1;
        i++;
    }
}

int main()
{
    int r[1000];

    int n;
    cin >> n;

    r[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        multiply(r, i);
    }
    for (int i = r_size - 1; i >= 0; i--)
    {
        cout << r[i];
    }
}