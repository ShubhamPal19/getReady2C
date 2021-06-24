#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <iterator>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class graph
{

    unordered_map<T, list<pair<T, int>>> h;

public:
    void addedge(T src, T des, int dist, bool bidir = true)
    {
        h[src].push_back(make_pair(des, dist));
        if (bidir)
        {

            h[des].push_back(make_pair(src, dist));
        }
    }

    void print_list()

    {

        for (auto node : h)
        {
            cout << node.first << "  :  ";
            for (auto neighbour : node.second)
            {

                cout << "(" << neighbour.first << "," << neighbour.second << ") ,";
            }
            cout << endl;
        }
    }

    void dijkastra(T src)
    {
        unordered_map<T, int> distance;

        for (auto node : h)
        {
            distance[node.first] = 10000;
        }

        distance[src] = 0;

        set<pair<int, T>> s;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {

            auto node = *(s.begin());
            s.erase(s.begin());
            int parentdist = node.first;
            T parent = node.second;
            for (auto children : h[parent])
            {
                int edgedist = children.second;
                if (distance[children.first] > edgedist + parentdist)
                {

                    auto f = s.find(make_pair(distance[children.first], children.first));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    distance[children.first] = edgedist + parentdist;
                    s.insert(make_pair(distance[children.first], children.first));
                }
            }
        }
        // for (auto  node : h)
        // {
        //     for(auto neighbour : node.second)
        //     {
        //         if (neighbour.second+distance[node.first] < distance[neighbour.first])
        //         {
        //             distance[neighbour.first]=neighbour.second+distance[node.first];
        //         }

        //     }

        // }
        cout << "distance of following nodes from " << src << " is : " << endl;
        for (auto node : distance)
        {
            cout << node.first << "   " << node.second << endl;
        }
    }
};

int main()
{
    graph<string> g;

    g.addedge("A", "Ag", 1);
    g.addedge("A", "J", 4);
    g.addedge("D", "J", 1);
    g.addedge("D", "Ag", 1);
    g.addedge("B", "Ag", 2);
    g.addedge("B", "M", 3);
    g.addedge("J", "M", 1);

    g.print_list();

    g.dijkastra("A");
}
