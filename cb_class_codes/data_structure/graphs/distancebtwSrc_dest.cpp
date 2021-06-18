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

    int min_distance(T start)
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        unordered_map<T, int> distance;
        distance[start]=0;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto children : h[node])
            {
            
                if (!visited[children])
                {   
                    
                    q.push(children);
                    distance[children]= distance[node]+1;
                    visited[children] = true;
                }
                // else  //not required for bfs min distance
                // {
                //     distance[children]=min(distance[children],distance[node]+1);
                // }

            }
        }

        cout << "Min distance form source to other nodes is : \n   Node        distance\n";

        for( auto n : distance)
        {
            cout<<"   " <<n.first<<"    " <<n.second<<endl;
        }
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
 g.min_distance(0);

}


// 6 7


// 1 0
// 0 4
// 4 2
// 2 1
// 2 3
// 3 4
// 3 5
 