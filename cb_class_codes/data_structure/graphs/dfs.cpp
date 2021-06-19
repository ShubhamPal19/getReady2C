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

    g.dfs(0);
}

// 6 7

// 1 0
// 0 4
// 4 2
// 2 1
// 2 3
// 3 4
// 3 5
