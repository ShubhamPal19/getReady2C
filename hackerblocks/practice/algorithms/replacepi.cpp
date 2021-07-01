// Replace all occurrences of pi with 3.14

// Input Format
// Integer N, no of lines with one string per line

// Constraints
// 0 < N < 1000
// 0 <= len(str) < 1000

// Output Format
// Output result one per line

// Sample Input
// 3
// xpix
// xabpixx3.15x
// xpipippixx
// Sample Output
// x3.14x
// xab3.14xx3.15x
// x3.143.14p3.14xx
// Explanation
// All occurrences of pi have been replaced with "3.14".

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t;
    int cindex=0;
    string s,temp;
    string pi="3.14";


    cin>>t;

    for (int i = 0; i < t; i++)
    {
        cin>>s;
      int len=s.length();
      for (int j = 0; j < len; j++)
      {
          if (s[j]=='p')
          {
              if (s[j+1]=='i')
              {
                  s.push_back(s[len-2]);
                  s.push_back(s[len-1]);

                for (int k = len - 1; k >= j+4; k--)
                {
                    s[k]=s[k-2];
                }
                for (int k = 0; k < 4; k++)
                {
                    s[j+k]=pi[k];
                }
                
              }
              
          }

          len=s.length();
          
      }

      cout<<s<<endl; 
    }

    cout<<LONG_LONG_MAX<<endl;
    int i;
    cin>>i;
    cout <<i;
    
}