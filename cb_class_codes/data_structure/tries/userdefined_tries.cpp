#include <iostream>
#include <unordered_map>

using namespace std;

class node

{

    char data;

public:
    unordered_map<char, node *> h;
    bool isterminal;
    node(char c)
    {
        data = c;
        isterminal = false;
    }
};

class trie
{

    node *root;

public:
    trie()
    {
        root = new node('\0');
    }

    void insert(char *word)
    {
        node *temp = root;
        for (int i = 0; word[i]; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch))
            {
                temp = temp->h[ch];
            }
            else
            {
                temp->h[ch] = new node(ch);
                temp = temp->h[ch];
            }
        }
        temp->isterminal = true;
    }


    bool search( char *key)
    {
        node * temp= root;  
        for (int i = 0; key[i]; i++)
        {
            char ch= key[i];

            if(temp->h.count(ch))
            {
                temp=temp->h[ch];
            }
            else
              return false;
        }

        return temp->isterminal;
        
    }
};



int main()
{
    trie t;
    t.insert("hello");
    t.insert("helloworl");
    t.insert("helloshubham");
    t.insert("code");
    t.insert("coding");
    t.insert("coder"); 

    cout<< t.search("hello") <<endl;


}