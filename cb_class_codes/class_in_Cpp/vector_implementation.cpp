#include<iostream>

using namespace std;

class vector
{

    public:
    int *arry;
    int v_size;
    int v_capacity;

    void push_back(int data)
    {

        if (v_size==v_capacity)
        {
            int *temp;
            temp=arry;
           arry=new int[v_capacity*2];
           for(int i = 0; i < v_size; i++)
           {
               arry[i]=temp[i];

               
           }
           v_capacity*=2;
           arry[v_size++]=data;
           delete []temp;
           
        }
        
        else
        {

            arry[v_size++]=data;
        }


    }
    vector(int s=2){   //default argument

        v_capacity=s;
        v_size=0;
        arry=new int[v_capacity];
    }

    void pop_back()
    {
        if (v_size>=0)
        {
           v_size--;
        }
        


    }


    int size()
    {
        return v_size;
        
    }
    int capacity()
    {
        return v_capacity;

    }
    void print()
    {
        
        for (int i = 0; i < v_size; i++)
        {
            cout<< arry[i]<< "  ";
        }
        cout<< endl;
    }

    int operator[](int i){
        return arry[i];

    }


};

int main()
{
    vector v;
    v.push_back(23);
    v.push_back(23);
    v.push_back(23);
    v.push_back(2);
   cout<< v.size()<<endl;
    v.print();

   cout<< v[3]<<endl;  // operator overloading
   return 0;

}