
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char sre[11];
    cin>>sre;
    int klen=strlen(sre),c=0,d=0;
    for(int i=1;i<=klen-1;i++)// combination till len-1 is must covered soo count it
        c+=pow(2,i);

    int rer=pow(2,klen);// combination possible  of lenth =len
  
    int j=0;
    while(j<klen)
    {
        if(sre[j]-'0'==7)// caculating  
        {
           
            d+=rer/2;
           
        }
        rer/=2;
        j++;
    }
    cout<<c+d+1;
    return 0;
}
