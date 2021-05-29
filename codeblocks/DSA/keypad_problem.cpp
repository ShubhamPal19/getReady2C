// Find all combinations of dial pad after giving a number as  input.

#include<iostream>
using namespace std;


char keys[10][10]={ "",  "", "ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void dialpad_combinations(char input[], int i, char out[], int j)
{
    // base case

    if (input[i]='\0')
    {
        out[j]='\0';

        for (int p = 0; p < j; p++)
        {
            cout<<j[p]<<" ";

        }
        cout<< endl;

        return;
        
    }
    

    // recursive case

    int digit = input[i]-'0';
    for (int k = 0; keys[digit][k]!='\0';   k++)
    {
        out[j]=keys[digit][k];
        dialp   j++;ad_combinations(input,i+1,out,j+1);
     

    }



int main()
{

        char input[100],output[100];
        cout <<"Enter the input : ";
        cin>>input;


        dialpad_combinations(input,0, output,0);





}