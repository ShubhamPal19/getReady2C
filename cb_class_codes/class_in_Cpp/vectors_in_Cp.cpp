#include<iostream>

#include <vector>
using namespace std;

int main(){

    vector<int> v;   // vector is growable array which increases exponentially

    v.push_back(237);
    v.push_back(27);

    cout<< "\nSize is : " <<v.size()<<endl;
    cout<< "capacity is : "<<v.capacity()<<endl;
    v.push_back(7);
    v.push_back(1);
    v.push_back(2);
    v.push_back(74);
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    cout<< "\nSize is : " <<v.size()<<endl;
    cout<< "capacity is : "<<v.capacity()<< endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i]<<" "  ;

    }

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout<< "\nSize is : " <<v.size()<<endl;
    cout<< "capacity is : "<<v.capacity()<< endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i]<<" "  ;

    }


    vector<int> ve[100];
    
    
    




}