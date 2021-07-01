// Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

// Input Format
// The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines, there are two numbers m and n separated by a space.

// Constraints
// 1 <= m <= n <= 1000000000 n-m<=100000

// Output Format
// For every test case print all prime numbers p such that m <= p <= n, all primes per line, test cases separated by an empty line.

// Sample Input
// 2
// 1 10
// 3 5
// Sample Output
// 2 3 5 7
// 3 5
// #include <vector>
// #include <iostream>
// using namespace std;

// vector<int> prime;
// int Max = 1000000000;
// bool notprime[1000000000] = {false};

// void generateprime()
// {

//     for (int i = 2; i < Max; i++)
//     {
//         if (!notprime[i])
//         {
//             prime.push_back(i);
//             for (int j = 2; j * i < Max; j++)
//             {
//                 notprime[i * j] = true;
//             }
//         }
//     }
// }


// int main()
// {
//     int t;
//     generateprime();
//     for(int i=0;i<1000;i++)
//     {
//         cout<<prime[i]<<" ";
//     }

//     int a,b;
//     cin>>t;
//     while (t--)
//     {
//         cin>>a>>b;

//         int i=0;
//         while (prime[i]<a) i++;
        

//         while(prime[i]<=b)
//         {
//             cout<<prime[i]<<" ";
//             i++;
//         }
        
//         cout<<endl;
//     }
  
// }




#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int t;

    cin >> t;
    vector<int> prime;
    prime.push_back(2);
    prime.push_back(3);
    int m,n;

    for (int i = 0; i < t; i++)
    {
        cin >>m>>n;
        if (prime[prime.size()-1] < n)
        {

            for (int j = prime[prime.size() - 1] + 1; prime.size() <= n; j++)
            {
                int flag = 1;

                for (int k = 0; prime[k] <= j / 2 + 1; k++)
                {
                    if (j % prime[k] == 0)
                    {
                        flag = 0;
                    }
                }
                if (flag)
                {
                    prime.push_back(j);
                }
            }
        }

        while (prime[i]<m) i++;
        while(prime[i]<=n)
        {
            cout<<prime[i]<<" ";
            i++;
        }
        cout<<endl;
    }

    return 0;
}