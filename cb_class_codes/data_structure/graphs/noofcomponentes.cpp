#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

template <typename T>
class graph
{


void dfshelper(T start, unordered_map<int, bool> &visited)
    {
        if (visited[start])
        {
            return;
        }
        cout << start << " ";
        visited[start] = true;

        for (auto node : h[start])
        {
            dfshelper(node, visited);
        }
    }
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

    

    void dfs(T start)
    {
        unordered_map<int, bool> visited;

        dfshelper(start, visited);
    }


    int countcomponents(T src)
    {
        int count=1;
        unordered_map<int,bool> visited;

        cout<< "component "<<count<<" : ";
        dfshelper(src,visited);
        cout<<endl;
        for (auto n : h)
        {
            if(!visited[n.first])
            {
                count++;
                cout<< "component "<<count<<" : ";
                dfshelper(n.first,visited);
                cout<<endl;

            }
        }

        return count;
        

    }
};

int main()
{
    int ne, nn;
    cin >> nn >> ne;

    graph<int> g;
    for (int i = 0; i < ne; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
    }
    int s = 0;

    cout<< "\nNumber of components in given graph is "<<g.countcomponents(0)<<endl;
}

// 16 17

// 1 0
// 0 4
// 4 2
// 2 1
// 2 3
// 3 4
// 3 5

// 11 10
// 12 10
// 12 13
// 12 15
// 15 13

// 21 20
// 20 24
// 24 22
// 22 21
// 22 23

 