#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;



template<typename T>
class graph
{

    unordered_map<T , list<pair<T,int> >  > h;
    public : 
    void addedge(T src, T des, int dist, bool bidir = true)
    {
        h[src].push_back(make_pair(des,dist));
        if (bidir)
        {
            
        
        h[des].push_back(make_pair(src,dist));
        }
        
    }


    void print_list()

    {

        for(auto node: h)
        {
           cout<< node.first << "  :  " ;
           for(auto neighbour : node.second)
           {

              cout<<"("<<neighbour.first<<","<<neighbour.second<<") ,";
           }
            cout<<endl;
        }
    }
};

int main()
{
    graph<string> g;

    g.addedge("A","Ag",1);
    g.addedge("A","J",4);
    g.addedge("D","J",1);
    g.addedge("D","Ag",1);
    g.addedge("B","Ag",2);
    g.addedge("B","M",3);
    g.addedge("J","M",1);

    g.print_list();
}
