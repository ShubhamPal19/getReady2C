
#include <iostream>
using namespace std;

template <typename t>
class node
{
public:
    node<t> *next;
    t data;

    node(t d)
    {

        next = NULL;
        data = d;
    }
};

template <typename t>
class queue
{
private:
    node<t> *head;
    node<t> *tail;
    int len;

public:
    void push(t d)
    {
        node<t> *n = new node<t>(d);

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        len++;
    }

    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
        }
        len--;
    }
    bool empty()
    {
        return head == NULL;
    }

    int size()
    {
        return len;
    }
    void print()
    {
        node<t> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " " << endl;
            temp = temp->next;
        }

        cout << endl;
    }

    int front()
    {
        return head->data;
    }
};

int main()
{

    queue<int> q;
    q.push(3);
    q.push(34);
    q.print();
    cout <<q.size()<<endl;
}
