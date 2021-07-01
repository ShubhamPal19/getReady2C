
// Given a list, modify it such that all odd elements appear before the even ones. The order of odd elements and even shall remain intact.

// See explantaion for more info.

// Input Format
// The first line contains an integer N, the number of elements in the list.

// The next line contains N space separated integral elements of the list.

// Constraints
// 1 <= T <= 1000 0 <= N <= 10^6

// Output Format
// T lines of output

// Sample Input
// 5
// 1 2 3 4 5
// Sample Output
// 1 3 5 2 4
// Explanation
// Input : 1 -> 2 -> 3 -> 4 -> 5

// The order of odd elements and even does not change. For instance 3 comes before 5 in the input, so comes in the output.

// Output: 1 -> 3 -> 5 -> 2 -> 4

#include <iostream>

using namespace std;

// int main()
// {

//     int *a;
//     int n;
//     cin >> n;
//     a = new int[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     int p=0;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] % 2 == 1)
//         {
//             p++;
//         }
//     }
//     int even = p;
//     int temp;
//     int i = 0;
//     while (i != p)
//     {
//         if (a[i] % 2 == 0)
//         {
//             temp = a[even];
//             a[even++] = a[i];

//             for (int j = i; j < p - 1; j++)
//             {
//                 a[i] = a[i + 1];
//             }
//             a[p - 1] = temp;
//         }
//         else
//             i++;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }
// }

class node
{
public:
    int data;
    node *next;

    node(int t)
    {
        data = t;
        next = NULL;
    }
};

int main()
{
    int n, data;
    cin >> n;
    node *head = NULL;
    node *tail = NULL;
    cin >> data;

    head = new node(data);
    tail = head;
    for (int i = 1; i < n; i++)
    {

        cin >> data;
        tail->next = new node(data);
        tail = tail->next;
    }

    node *temp1, *temp2, *temp3;

    temp2 = head;
    if (head->data % 2 == 0)
    {
        temp1 = head->next;

        while (temp1->data % 2 == 0)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }

        tail->next = head;
        head = temp1;
        temp2->next = NULL;
    }

    temp3 = temp1;
    temp1 = temp1->next;

    while (temp1 != tail->next)
    {

        if (temp1->data % 2 == 0)
        {
            temp2->next = temp1;
            temp3->next = temp1->next;
            temp2 = temp1;
            temp2->next = NULL;
            temp1 = temp3->next;
        }
        else
        {
            temp3 = temp1;
            temp1 = temp1->next;
        }
    }
    tail = temp2;
    temp1 = head;
    while (temp1)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
}