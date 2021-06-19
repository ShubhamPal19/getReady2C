#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

template <typename T>
class graph
{

public:
    unordered_map<T, list<T>> h;
    // void addedge(T a, T b, bool bd = false)
    void addedge(T a, T b, bool bd = true)
    {

        h[a].push_back(b);
        if (bd)
        {

            h[b].push_back(a);
        }
    }

    void printlist()
    {

        for (auto node : h)
        {
            cout << node.first << "--->";
            for (auto n : node.second)
            {
                cout << n << ",";
            }
            cout << endl;
        }
    }

    void printpathrecursive(T start, T end,   unordered_map<T, T> parent )
    {
        if (start==end)
        {
            cout<<start<<" --> ";
        return;
        }
            
      printpathrecursive(start, parent[end], parent);
      cout<<end<<" --> ";
    }
    void printpath(T start,T end)
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;
        parent[start]=start;
       
        q.push(start);
        visited[start] = true;
        int flag = !(start==end);
        while (!q.empty() && flag)
        {
            T node = q.front();
            q.pop();
            for (auto children : h[node])
            {
            
                if (!visited[children])
                {   
                   
                    
                    q.push(children);
                    parent[children]=node;
                   
                    visited[children] = true;
                    
                    
                     if (children==end)
                    {
                        flag=0;
                        break;
                    }
                }
             

            }
           
            
        }
        printpathrecursive(start, end , parent);
        
    }
}; 

int main()
{
int ne,nn;
    cin>>nn>>ne;

    graph<int> g;
    for (int i = 0; i < ne; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
        
    }
    int s=0;
   g.printpath(0,5);

}


// 6 7


// 1 0
// 0 4
// 4 2
// 2 1
// 2 3
// 3 4
// 3 5
 