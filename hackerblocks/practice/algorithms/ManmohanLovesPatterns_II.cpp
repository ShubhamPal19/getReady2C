// // Help Manmohan to print pattern of a given number. See the output pattern for given input n = 5.

// // Input Format
// // Single integer N denoting number of lines of the pattern.

// Sample Output
// 1
// 11
// 202
// 3003
// 40004



#include <iostream>
using namespace std;



int main()
{
    int n;

    cin>> n;  

    if(n>0) 
    {
        cout<<1<<endl;
    }
  for (size_t i = 1; i < n; i++)
  {
      cout<<i;
      for (size_t j = 0; j < i-1; j++)
      {
          cout<<0;
      }
      cout<<i<<endl;
  }

  return 0;
}


#include <iostream>
using namespace std;

int main()
{


    return 0;
}