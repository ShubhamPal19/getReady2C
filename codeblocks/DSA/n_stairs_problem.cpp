#include <iostream>
#include <string.h>
using namespace std;


int count_number_of_ways(int n, int k)
{
   if(n==0)
   {
       return 1;
       
   }
   if(n<0)
   {
       return 0;
       
   }
   int way=0;
    for(int i=1; i<=k; i++) 
    {
        way= way + count_number_of_ways(n-i,k);
        
    }
    return way;
    
}

int main() {
    
   int n,k;
   
   cout << "Enter the value of n(number of stairs) and k(max num of steps can be taken in one lap): ";
   
   cin>>n>>k;
   
   int ways= count_number_of_ways(n,k);
   cout <<"The number of ways to reach at nth stair is "<<ways<<"."<<endl;
	return 0;
}
