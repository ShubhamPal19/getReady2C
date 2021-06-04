#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    if (s.empty)
    {
        cout<<"EMotew";

    }
    

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"Top is "<<s.top<<endl;

}
