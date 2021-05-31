#include<iostream>
using namespace std;
class car
{

public:
    int x;
    int y;

    int operator>(car t)
    {
        if (x>t.x && y > t.y)
        {
             return 1;
        }
        else if (x<t.x && y < t.y)
        {
             return 0;
        }
        else
         return -1;
    }
     

};

int main()
{

   car a;
   car b;
    a.x=30;
    a.y=10;
    b.y=899;
    b.x=233;



  
    switch (a > b)
    {
    case 1:
        cout<< "A is greater than B.";
       break;
    case 0:
        cout<< "B is greater than A.";
       break;
    case -1:
        cout<< "can't compare with these values.";
       break;
    
    default:
        break;
    }

  
}