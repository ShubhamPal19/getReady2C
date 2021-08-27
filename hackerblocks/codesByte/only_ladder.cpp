// Take as input N, a number. N is the size of a snakes and ladders board. There are no snakes but we’ve ladders from 1st prime number to last prime number in range, 2nd prime number to 2nd from last prime number and so-on.

// a. Write a recursive function which returns the count of different distinct ways this board can be crossed with a normal dice. Print the value returned.

// b. Write a recursive function which prints all valid paths (void is the return type for function).

// Input Format
// Enter the size of the snake and ladders board N

// Constraints
// None

// Output Format
// Display the number of ways in which the board can be crossed and also display all the possible ways to cross the board in a comma separated manner

// Sample Input
// 3
// Sample Output
// 0 1 2 END , 0 1 END , 0 2 END , 0 END , 
// 4


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> prime;

bool *isprime;

void generateprime(int n)
{
    isprime = new bool[n + 1];

    for (size_t i = 0; i < n + 1; i++)
    {
        isprime[i] = true;
    }

    int j, k;
    for (size_t i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            k = i * 2;
            j = 3;
            while (k <= n)
            {
                cout << "value of k is " << k << endl;
                isprime[k] = false;
                k = i * j;
                j++;
            }
        }
    }
    delete[] isprime;
}

int * board,count=0,n;

vector<int> path;
void printpath(int position)
{
    

    if(position==n)
    {
        count++;
        for (size_t i = 0; i < path.size()-1; i++)
        {
            cout<<path[i]<< " ";

        }
        cout<<"END , ";
        return;
    }


    if (board[position]!=0)
    {
        path.push_back(position);
        printpath(position+board[position]);
        path.pop_back();
        return;
    }
    

    for (size_t i = 1; position+i<=n && i <= 6; i++)
    {
        path.push_back(position+i);
        printpath(position+i);
        path.pop_back();
    
    }
}



int findpath()
{
    int position=0;
    path.push_back(position);
    printpath(position);
    cout<<endl;
    return count;
}

int main()
{
   
    cin >> n;
    generateprime(n);

    
    board = new int[n + 1];
    memset(board, 0, n + 1);
    int i = 0, j = prime.size() - 1;


    while (i < j)
    {
    
        board[prime[i]] = prime[j] - prime[i];
        i++;
        j--;
    }

    cout<<findpath();
}
