#include <iostream>
#include <stack>
using namespace std;


void push_at_bottom(stack<int> &s, int data)
{
    if (s.size()==0)
    {
        s.push(data);
        return;
    }
    
    int top=s.top();

    s.pop();
    push_at_bottom(s,data);
    s.push(top);
}   

void reversestack(stack<int> &s)
{
    
    if (s.size()==1)
    {
        return;
    }
    
     
     //reverse stack

     int top=s.top();
     s.pop();
     reversestack(s);

    push_at_bottom(s,top);

     
}

void print(stack<int> s)
{

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();

    }
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reversestack(s);
    cout << "Reversed stack is ->"<<endl;
    
    print(s);

} 