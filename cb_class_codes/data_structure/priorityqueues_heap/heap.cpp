#include <iostream>
#include <vector>
using namespace std;

class heap
{
private:
    void heapify(int i)
    {
        int min_index = i;
        int left = i * 2;
        int right = left + 1;
        if (right<v.size()&& v[min_index] > v[right])
        {
            min_index = right;
        }
        
        if (left< v.size() && v[min_index] > v[left])
        {
            min_index = left;
        }

        if (i != min_index)
        {
            swap(v[min_index], v[i]);
            heapify(min_index);
        }
    }
public:
    vector<int> v;
    heap()
    {
        v.push_back(-1);
    }
    void push(int d)
    {
        v.push_back(d);
        int c = v.size() - 1;
        int p = c / 2;
        while (c > 1 && v[p] > v[c])
        {
            swap(v[p], v[c]);
            c = p;
            p = p / 2;
        }
    }
    int top()
    {
        return v[1];
    }

    void pop()
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }

    bool empty()
    {
        return v.size()==1;
    }
};

int main()
{

    heap h;
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


    for (int i = 0; i < h.v.size(); i++)
    {
        cout <<h.v[i]<<  "   ";
    }
    cout <<endl;
    while (!h.empty())
    {
        cout<<h.top()<<endl;
        h.pop();
    }
    cout <<endl;
    

}