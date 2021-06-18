///Find the maximum length of subsequece in two strings given to you.


#include <iostream>
#include <string>


using namespace std;


// bugg ---> if two same  characters come after one another then the result would be 1 more than original result
int dp[100][100];
int l1,l2;
int maxlengthsubsequence(string s1,string s2)
{
  
  l1=s1.length();
  l2=s2.length();
    int initialisation=0,i,j;
  if (s1[l1-1]==s2[l2-1])
  { 
      initialisation=1;
  }

  for ( i = 0; i < l1; i++)
  {
      dp[i][l2-1]=initialisation;
      
  }
  for ( j = 0; j < l2; j++)
  {
      dp[l1-1][j]=initialisation;
  }

  
  
  




  for ( i = l1-2; i >=0; i--)
  {
      for ( j = l2-2; j >= 0; j--)
      {
          int Max=max(dp[i+1][j],dp[i][j+1]);
          if (s1[i]==s2[j])
          {
              dp[i][j]=Max+1;
              
              
          }
          else 
            dp[i][j]=Max;
      }
      
      
  }
  return dp[0][0];
}



int main()
{

    string s1,s2;
    s1="progra8ming";
    s2="pregarming";
  
    
    cout << "Max length is "<< maxlengthsubsequence( s1,s2)<<endl;
    for(int i=0;i<l1;i++)
    {
        for (int j = 0; j <l2; j++)
        {
            cout<< dp[i][j]<<"     ";
        }
        cout<<endl;
    }

}



// 9     8     7     7     7     7     5     3     2     1
// 8     8     7     7     7     7     5     3     2     1
// 7     7     7     7     6     6     5     3     2     1
// 7     7     7     7     6     6     5     3     2     1
// 7     7     6     6     6     6     5     3     2     1
// 6     6     6     6     6     5     5     3     2     1
// 5     5     5     5     5     5     5     3     2     1
// 4     4     4     4     4     4     4     3     2     1
// 3     3     3     3     3     3     3     3     2     1
// 2     2     2     2     2     2     2     2     2     1
// 1     1     1     1     1     1     1     1     1     1
// // 


// 8     7     6     6     6     6     4     3     2     1    
// 7     7     6     6     6     6     4     3     2     1    
// 6     6     6     6     5     5     4     3     2     1    
// 6     6     6     6     5     5     4     3     2     1    
// 6     6     5     5     5     5     4     3     2     1     
// 5     5     5     5     5     4     4     3     2     1    
// 4     4     4     4     4     4     4     3     2     1    
// 4     4     4     4     4     4     4     3     2     1    
// 3     3     3     3     3     3     3     3     2     1     
// 2     2     2     2     2     2     2     2     2     1     
// 1     1     1     1     1     1     1     1     1     1 