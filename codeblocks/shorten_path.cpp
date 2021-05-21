

// A person wants to go from origin to a particular location,
// he can move in only 4 directions(i.e East, West, North, South) but his friend gave him a long route,
// help a person to find minimum Moves so that he can reach to the destination.

// Note: You need to print the lexicographically sorted string. Assume the string will have only ‘E’ ‘N’ ‘S’ ‘W’ characters.

#include <iostream>
#include <string>

using namespace std;

void print_path(string * path, int lenght)
{

    cout<< (* path);


    
    

    


}

int main()

{
    string long_route, short_route = "";

    cout << "Enter the long route given by his friend(capital letters only) : "<<endl;
    cin >> long_route;

    int x = 0, y = 0, i = 1, j;
    char c;
    c = long_route[0];
    while (c != '\0')
    {
        if (c == 'N')
            y++;
        else if (c == 'S')
            y--;
        else if (c == 'W')
            x--;
        else if (c == 'E')
            x++;

        else
        {
            cout << "WRONG INPUT.";
            exit(1);
        }
        c = long_route[i++];
    }

    char dir1, dir2;
    int step1, step2; // stores number of steps in each direction dir1 and dir2;

    if (x > 0)
    {
        step1 = x;
        dir1='E';
    }
    else
    {
        step1 = (-1) * x;
        dir1='w';
    }
    if (y > 0)
    {
        step2 = y;
        dir2='N';
    }
    else
    {
        step2 = (-1) * y;
        dir2='S';
    }

    if (dir2<dir1){   
        dir2=dir1+dir2-(dir1=dir2);  
        step2=step1+step2-(step1=step2);  
    }

    for (size_t i = 0; i < step1; i++)
    {
        short_route.push_back(dir1);             
    }
    for (size_t i = 0; i < step2; i++)
    {
        short_route.push_back(dir2);         
    } 


    print_path(&short_route, (step1+step2));
    
    


}
