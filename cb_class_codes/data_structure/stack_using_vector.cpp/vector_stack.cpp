
#include <iostream>
#include <vector>

using namespace std;
template<typename T>
class stack
{
private:      // to maintain the property of stack so that we can not access the elements in between stack.
    vector<T> v;

public:
    T top()
    {
        return v[v.size() - 1];
    }
    void push(T data)
    {

        v.push_back(data);
    }
    void pop()
    {

        v.pop_back();
    }
    bool isempty()
    {
        return v.size() == 0;
    }

    int size()
    {
        return v.size();
    }
};

int main()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Top is " << s.top() << endl;
    s.pop();
    cout << "Top is " << s.top() << endl;
}