#include<iostream>

using namespace std;


void toh(int n, char src, char destination, char helper)
{

    if (n==0)
    {
        return;
    }
    toh(n-1,src,helper,destination);
    cout<<"Place disk "<<n<<" from "<< src << " to "<< destination<<"."<<endl;
    toh(n-1,helper,destination,src);
}


int main()
{

    int n;
    cout << "Enter the value of n : ";

    cin>>n;

    toh(n,'A','C','B');
}