#include <iostream>
using namespace std;
int add(int a = 0, int b = 0, int c = 0, int d = 0 )

{

    return a + b + c + d;
}
int main()
{

    cout << add(1, 3, 5, 6) << endl;
    cout << add() << endl;
}