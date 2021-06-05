#include <iostream>
using namespace std;

class queue
{
private:
    int *array, start, end, n, cs;

public:
    queue(int s=100)
    {
        n = s;
        array = new int(n);
        end = -1;
        start = 0;
        cs = 0;
    }
    void pop()
    {
        if (end < start)
        {
            return;
        }
        start = (start + 1) % n;
        cs--;
    }
    void push(int d)
    {
        if (end != start + n - 1)
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

        return end < start;
    }
    int front()
    {
        return array[start % n];
    }

    void print()
    {
        if (empty())
            return;
        for (int i = start; i <= end; i++)
        {
            cout << array[i % n] << " ";
        }

        cout << endl;
    }
};

class stack
{

private:

    queue q1;
        queue q2;
   
    queue *main, *helper;

public:
    stack()
    {
        
        main = &q1;
        helper = &q2;
    }

    void push(int data)
    {
        helper->push(data);
        while (!main->empty())
        {
            helper->push(main->front());
            main->pop();
        }
        queue *temp;
        temp = main;
        main = helper;
        helper = temp;
    }

    void pop()
    {
        if (main->empty())
        {
            cout << "empty queue!!!" << endl;
            return;
        }

        main->pop();
    }
    int top()

    {
        return main->front();
    }
    bool empty()
    {
        return main->empty();
    }

    int size()
    {
        return main->size();
    }

    void print()
    {
        main->print();
    }
};

int main(int argc, char const *argv[])
{
    stack s;

    cout << s.size() << endl;
    s.push(32);
    s.push(3);
    s.push(31);

    s.print();
    cout << s.size() << endl;
    return 0;
}
