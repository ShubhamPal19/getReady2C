#include<iostream>

using namespace std;


void subsequence(char in[],int i, char out[0],int j)
{
    if (in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }


    subsequence(in,i+1,out,j);
    out[j]=in[i];
    subsequence(in, i+1,out,j+1);
    


}


int main(){

    char in[100],out[100];
    cin>>in;

    subsequence(in,0,out,0);

   
}