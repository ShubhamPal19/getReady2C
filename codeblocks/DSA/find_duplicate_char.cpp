#include <iostream>
#include <string.h>
#include<cstdlib>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int len, l, i, *array;
    char temp;
    len = str.length();
    
   

    array = (int *)calloc(len,4);
    for (l=0;l<len;l++)
    {
      
        if (*(array + l)==-1)
        {
           
           continue;
        }
        *(array+l) +=1;
        i=l+1;
        while(i<len)
        {
            if (str[l]==str[i] )
            {
               *(array+l) +=1;
               *(array +i)=-1;
            }
            i++;
            
        }
       
    }

    cout<< " Duplicate character \t Frequency "<<endl;
    for (size_t i = 0; i < len; i++)
    {
       if (*(array + i)<2)
       {
           continue;
       }
       
       cout << "   \t" <<str [i]<<"\t\t\t"<< *(array +i)<<endl;
    }
    
    
    

}