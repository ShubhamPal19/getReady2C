#include <iostream>

using namespace std;

class queue
{
private:
    int *array, front, end, n, cs;

public:
    queue(int s)
    {
        n = s;
        array = new int(n);
        end = -1;
        front = 0;
        cs = 0;
    }
    void pop()
    {
        if (end < front)
        {
            return;
        }
        front = (front + 1) % n;
        cs--;
    }
    void push(int d)
    {
          if (end!= front+n-1)
            {

                end = (end + 1) % n;
                array[end] = d;
                cs++;
            }

            else
            {
                cout << "queue is full!!! \n";
            }
        
    }
    int size()

    {
        return cs;
    }
    bool empty()
    {
        return end < front;
    }
    int fornt()
    {
        return array[front % n];
    }

    void print()
    {
        if (empty())
            return;
        for (int i = front; i <= end; i++)
        {
            cout << array[i % n] << " ";
        }

        cout<<endl;

    }
};

int main()
{
    int n =9;

    queue q(n);
    q.push(3);
    q.push(34);
    q.print();
    cout << q.size() << endl;
}
