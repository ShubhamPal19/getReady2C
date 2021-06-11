#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class node
{

private:

public:
    string key;
    int val;
    node *next;
    node(string k, int v)
    {

        val = v;
        key = k;
        next = NULL;
    }
};

class hashmap
{
    int ts;
    int cs;
    node **arr;

public:


    int hashfunction(string key)
    {
        int ans=0;
        int mul=1;
        for (int  i = 0; i < key.length(); i++)
        {
            ans =  ans + (key[i]%ts)*( mul%ts);
            mul=(29*mul)%ts;


        }


        return ans%ts;

        
    }
    void rehashing()
    {
        node ** oldarr=arr;
        int oldts=ts,i;
        arr=(node **)calloc(ts*2,sizeof(node **));
        ts=2*ts;
        cs=0;
        for ( i = 0; i < oldts; i++)
        {
            node * head= oldarr[i],*temp;
            while (head)
            {
                int index = hashfunction(head->key);
       
                temp=head;
                head=head->next;
                arr[index] = temp;
                temp->next=NULL;
                cs++;
       
            }
            
            arr[i]=oldarr[i];
            if (arr[i])
            {
                cs++;
            }
            
        }
        delete[]oldarr;  
        
    }

    hashmap(int size = 7)
    {
        cs = 0;
        ts = size;
        arr = (node **)calloc(size, sizeof(node **));
    }

    void insert(string key,int val)
    {
        int index = hashfunction(key);
        node *n = new node(key, val);
        n->next = arr[index];
        arr[index] = n;
        cs++;

        if (cs / ts * 1.0 > 0.6)
        {
            rehashing();
        }
    }

    void print()
    {
        for (int i = 0; i < ts; i++)
        {

            cout << i <<" --->" ;
            node *head=arr[i];
            while (head != NULL)
            {
                cout << head->key << "  ";
                head = head->next;
            }
            cout << endl;
        }
    }


    node * search(string key)
    {
        int index=hashfunction(key);
        node * head = arr[index];
        while (head)
        {
            if(head->key == key)
            {
                return head;
            }
        }
        return NULL;


    }
};



int main()
{
    hashmap h;

    h.insert("mango",1200);
    h.insert("kiwi",1300);
    h.insert("orange",1500);
    h.print();
    cout <<endl;
    h.insert("jamun",2100);
    h.insert("banana",4500);
    h.insert("apple",200);
    h.insert("lemon",120);
    h.insert("tomato",400);
    h.insert("grapes",5200);
    h.print();
    cout <<endl;
}


