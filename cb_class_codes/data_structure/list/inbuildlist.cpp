#include <iostream>

#include <list>
using namespace std;

int main()
{

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

while (!l.empty())
{
    cout<<l.front()<<" ";
    l.pop_front();
}



}