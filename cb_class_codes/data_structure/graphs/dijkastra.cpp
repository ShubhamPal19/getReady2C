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


    void dijkastra(T src)
    {
        unordered_map<T,int> distance;

        for(auto node: h)
        {
            distance[node.first]=10000;
        }
        
        distance[src]=0;

        for (auto  node : h)
        {
            for(auto neighbour : node.second)
            {
                if (neighbour.second+distance[node.first] < distance[neighbour.first])
                {
                    distance[neighbour.first]=neighbour.second+distance[node.first];     
                }
                
            }
            
        }
    cout<<"distance of following nodes from "<<src <<" is : "<<endl;
        for (auto node : distance)
        {
            cout<< node.first <<"   " <<node.second<<endl;
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
    
    
        g.dijkastra("A");
}



M  :  (B,3) ,(J,1) ,
D  :  (J,1) ,(Ag,1) ,
B  :  (Ag,2) ,(M,3) ,
J  :  (A,4) ,(D,1) ,(M,1) ,
A  :  (Ag,1) ,(J,4) ,
Ag  :  (A,1) ,(D,1) ,(B,2) ,
 before if  node is M neighbour is : B pre-distance 10000  after-distance is 10003
 before if  node is M neighbour is : J pre-distance 10000  after-distance is 10001
 before if  node is D neighbour is : J pre-distance 10000  after-distance is 10001
 before if  node is D neighbour is : Ag pre-distance 10000  after-distance is 10001
 before if  node is B neighbour is : Ag pre-distance 10000  after-distance is 10002
 before if  node is B neighbour is : M pre-distance 10000  after-distance is 10003
 before if  node is J neighbour is : A pre-distance 0  after-distance is 10004
 before if  node is J neighbour is : D pre-distance 10000  after-distance is 10001
 before if  node is J neighbour is : M pre-distance 10000  after-distance is 10001
 before if  node is A neighbour is : Ag pre-distance 10000  after-distance is 1
node is A neighbour is : Ag pre-distance 10000  after-distance is 1
 before if  node is A neighbour is : J pre-distance 10000  after-distance is 4
node is A neighbour is : J pre-distance 10000  after-distance is 4
 before if  node is Ag neighbour is : A pre-distance 0  after-distance is 2
 before if  node is Ag neighbour is : D pre-distance 10000  after-distance is 2
node is Ag neighbour is : D pre-distance 10000  after-distance is 2
 before if  node is Ag neighbour is : B pre-distance 10000  after-distance is 3
node is Ag neighbour is : B pre-distance 10000  after-distance is 3
distance of following nodes from A is : 
Ag   1
A   0
J   4
B   3
M   10000
D   2
