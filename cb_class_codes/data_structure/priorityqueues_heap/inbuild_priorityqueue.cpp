#include <iostream>
#include <queue>
using namespace std;



int main()
{

    // priority_queue<int> h; // ----> max heap
    priority_queue<int, vector<int>,greater<int> > h; // ----> min heap

    h.push(23);
    h.push(1);
    h.push(3);
    h.push(223);
    h.push(233);
    h.push(21);
    h.push(43);
    h.push(256);
    h.push(86);
    h.push(243);
    h.push(2203);
    h.push(12);


    while (!h.empty())
    {
        cout<<h.top()<<endl;
        h.pop();
    }
    cout <<endl;
    

}