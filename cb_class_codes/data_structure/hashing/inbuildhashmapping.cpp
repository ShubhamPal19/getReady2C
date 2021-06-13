#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> h;
    h["guddt"] = 4993;

    for (auto f : h)
    {
        cout << f.first << " " << f.second << endl;
    }
  
}