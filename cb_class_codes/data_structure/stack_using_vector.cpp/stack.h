#include"node.h"
using namespace std;


template<typename T>
class stack
{
private:
    node<T> * head;
    int length;

public:


    stack()
    {
        head=NULL;
        length=0;

    }

    T top()
    {
            return head->data;
    }

    void push(T key)
    {   
        node<T> * temp;
        temp = new node<T>(key);
        temp->next =head;
        head=temp;
        length++;
        


    }
    void pop()
    {
        if (empty())
        {
            cout<<"Empty stack!!!"<<endl;

            return;
        }
        
        node<T> * temp;
        temp=head;
        head=head->next;
        delete temp;

        length++;
    }

    int size()

    {
        return length;

    }
    bool empty()
    {
        return head==NULL;
    }




    

};

