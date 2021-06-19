#include <iostream>
#include <list>

using namespace std;
class graph // bidirectional
{
    public:
    list<int> *l;
     
    int n;
    graph(int N)
    {
        n=N;
          l= new list<int>[n];
       
    }

    void addedge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);

    }   

    void print()
    {
        
        for (int i = 0; i < n; i++)
        {
            cout<< i<< "------> ";
           for (int j = 0; j < l[i].size(); j++)
           {
               cout<<l[i].front()<<",";
             l[i].push_back( l[i].front());
             l[i].pop_front();
              
           }
           

            cout<< endl;
            
        }
        
    }
};
int main()
{
    int ne,nn;
    cin>>ne>>nn;

    graph g(nn);
    for (int i = 0; i < ne; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
        
    }



    g.print();
     
}