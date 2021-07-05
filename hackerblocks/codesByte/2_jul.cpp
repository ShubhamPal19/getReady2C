// Given an M × N binary matrix, fill it with alternating rectangles of 0 and 1.

// Input Format
// Two integers M and N.

// Constraints
// 0<=m,n<=50

// Output Format
// Resultant matrix

// Sample Input
// 10 8
// Sample Output
// 1 1 1 1 1 1 1 1
// 1 0 0 0 0 0 0 1
// 1 0 1 1 1 1 0 1
// 1 0 1 0 0 1 0 1
// 1 0 1 0 0 1 0 1
// 1 0 1 0 0 1 0 1
// 1 0 1 0 0 1 0 1
// 1 0 1 1 1 1 0 1
// 1 0 0 0 0 0 0 1
// 1 1 1 1 1 1 1 1



#include <iostream>

using namespace std;


int main()
{

    int m,n;
    cin >> m>> n;
    int sc,ec,sr,er;

    int i,j,k;
    sc=sr=0;
    ec=n-1;
    er=m-1;
    int element= 1;
    int a[50][50];


    // for ( i = 0; i < m; i++)
    // {
    //     cout<<" i "<<endl;
    //     a[i] = new int[n];
    // }
    

    while(sc<=ec || sr<= er)
    {
        for (j = sc; j <=ec; j++)
        {
            a[sr][j]= element;
            a[er][j]=element;

        }
        er--;
        sr++;
        for ( i = sr; i <=er; i++)
        {
            a[i][sc]=element;
            a[i][ec]=element;
        }
        
        sc++;
        ec--;

        element=1-element;

    }
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            cout<<a[i][j];
            cout<<" "; 
        }
        
            cout<<endl; 
    }
    


}