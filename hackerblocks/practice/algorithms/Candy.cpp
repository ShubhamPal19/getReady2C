// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {

//     int t;

//     cin >> t;
//     vector<int> prime;
//     prime.push_back(2);
//     prime.push_back(3);
//     int n;

//     for (int i = 0; i < t; i++)
//     {
//         cin >> n;
//         if (prime.size() < n)
//         {

//             for (int j = prime[prime.size() - 1] + 1; prime.size() <= n; j++)
//             {
//                 int flag = 1;

//                 for (int k = 0; prime[k] <= j / 2 + 1; k++)
//                 {
//                     if (j % prime[k] == 0)
//                     {
//                         flag = 0;
//                     }
//                 }
//                 if (flag)
//                 {
//                     prime.push_back(j);
//                 }
//             }
//         }
//         cout << prime[n - 1] << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000000
vector<bool>isPrime (MAX,true);
unsigned primearray[5761459];


void gen_primes(){
    isPrime[0]=isPrime[1]=false;
    for(unsigned i=2;i*i<=MAX;i++){
        if(isPrime[i]){
            for(unsigned j=i;j*i<=MAX;j++) isPrime[i*j]=false;
        }
    }
    unsigned idx = 1;
    primearray[0]=2;

    for(int i=3;i<=MAX;i+=2){
        if(isPrime[i]){
            primearray[idx++]=i;
        }     
    }
}

int main(int argc, char const *argv[])
{

    gen_primes();

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<primearray[n-1]<<endl;
    }
    return 0;
}
