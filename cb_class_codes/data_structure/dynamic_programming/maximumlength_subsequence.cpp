///Find the maximum length of subsequece in two strings given to you.


#include <iostream>
#include <string>


using namespace std;

int maxlengthsubsequence(int dp[][100],string s1,int i, string s2,int j)
{

    if(s1[i]=='\0' || s2[j]=='\0')
    {
        return  dp[i][j]=0;
    }
    if(dp[i][j]!=-1)
    {
       
        return dp[i][j];
    }
   
  
    if(s1[i]==s2[j])
    {

        return dp[i][j]=maxlengthsubsequence(dp,s1,i+1,s2,j+1)+1;

    }

   return dp[i][j]= max(maxlengthsubsequence(dp,s1,i+1,s2,j),maxlengthsubsequence(dp,s1,i,s2,j+1));
}



int main()
{

    string s1,s2;
    s1="progra1ming";
    s2="pregarming";
    cout <<s1<<s2;
    int dp[100][100];
    for(int i=0;i<s1.length();i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            dp[i][j]=-1;
        }
        
    }

    cout << "Max length is "<< maxlengthsubsequence(dp , s1,0,s2,0)<<endl;
    for(int i=0;i<s1.length();i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            cout<< dp[i][j]<<"     ";
        }
        cout<<endl;
    }

}


//  8     -1    -1    -1    -1    -1    -1    -1    -1    -1
// -1      7    -1    -1    -1    -1    -1    -1    -1    -1
// -1     -1     6     6     5     5     4     3     2     1
// -1     -1     6     6     5     5     4     3     2     1
// -1     -1     5     5     5     5     4     3     2     1
// -1     -1     5     5     5    -1     4     3     2     1
// -1     -1     4     4     4     4     4     3     2     1     
// -1     -1     4     4     4     4     4     3     2     1
// -1     -1     3     3     3     3     3     3     2     1
// -1     -1     2     2     2     2     2     2     2     1
// -1     -1     1     1     1     1     1     1     1     1








