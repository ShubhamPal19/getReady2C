
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

void addnode(node *&eh, node *&et, node *temp)
{

    if (eh == NULL)
    {
        eh = et = temp;
    }

    et->next = temp;
    et = temp;
}

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

    node *eh, *et, *oh, *ot;
    eh = oh = et = eh = NULL;
    node *temp1;
    while (head != NULL)
    {
        temp1 = head;
        head = head->next;
        temp1->next = NULL;

        if (temp1->data % 2 == 0)
        {
            addnode(eh, et, temp1);
        }

        else
        {
            addnode(oh, ot, temp1);
        }
    }

    ot->next = eh;
    head = oh;
    tail = et;

    temp1 = head;
    while (temp1)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
}