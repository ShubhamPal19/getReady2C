#include<iostream>
using namespace std;


// taking head as top

template<typename T>
class node
{
public:

    T data;
    node<T> * next;

    node(T d){
        next=NULL;
        data=d;
    }
};
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
        if (isempty())
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
    bool isempty()
    {
        return head==NULL;
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