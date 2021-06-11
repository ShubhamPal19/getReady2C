// you have to input products, when inputnum == -1 then throw output as three top products till now
// E.g. 1 4 5 2 -1 12 14 2 22 15 3 -1

// output--->   5 4 2       and      15 14 12

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
        if (right < v.size() && v[min_index] > v[right])
        {
            min_index = right;
        }

        if (left < v.size() && v[min_index] > v[left])
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
        return v.size() == 1;
    }
};

void top3products()
{
    int current_product, count = 0, k = 3;
    heap h;
    cout << "Enter the products (enter 0 to stop) : ";
    cin >> current_product;

    while (current_product)
    {
         int *p = new int[k];
        if (current_product == -1)
        {
           
            cout << "Top 3 products till now : ";
            for (size_t i = 0; i < k; i++)
            {
                p[i] = h.top();
                cout << p[i] << "  ";
                h.pop();
            }
            cout<<endl;
            
        for (size_t i = 0; i < k; i++)
        {
            h.push(p[i]);
        }
        
        }


        else
        {
            if (count < k)
            {
                h.push(current_product);
                count++;
            }
            else
            {
                if (current_product > h.top())
                {
                    h.pop();
                    h.push(current_product);
                }
            }
        }
        cin >> current_product;
    }
}

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

    while (!h.empty())
    {
        cout << h.top() << endl;
        h.pop();
    }
    cout << endl;
    top3products();
}