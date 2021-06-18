#include <iostream>
#include <cstring>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class graph
{

public:
    unordered_map<T, list<T> > h;
    void addedge(T a, T b, bool bd = false)
    {
        
        h[a].push_back(b);
        if (bd)
        {

            h[b].push_back(a);
        }
 }




    void printlist()
    {
    //   std::for_each(h.begin(),
    //             h.end(),
    //             [](const std::pair<T, list<T> > &p) {
    //                 std::cout << "{" << p.first << ": " << p.second << "}\n";
    //             });

    //    for ( *  i = h.cbegin; i !=h.cend; i++)
    //    {
           
    //    }
       
        for(auto node : h)
        {
            cout<<node.first<<"--->";
            for (auto n : node.second)
            {
                cout<<n<<",";
            }
            cout<<endl;
            
        }
        
        // for ( int i = 0; i < h.size(); i++)
        // {
        //     if(h[i])
        //     {
        //         cout<< h[i]<<" ";
        //     }
        // }
        
    }
};

int main()
{

    graph<string> g;
    g.addedge("s","t",true);
    g.addedge("g","t",false);
    g.addedge("p","g",true);
    g.addedge("g","b",false);
    g.addedge("b","t",true);



    g.printlist();

    
}