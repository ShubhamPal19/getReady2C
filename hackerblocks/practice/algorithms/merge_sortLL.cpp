// Given 2 sorted linked lists , merge the two given sorted linked list and print the final Linked List.

// Input Format
// First Line contains T the number of test cases.
// For each test case :
// Line 1 : N1 the size of list 1
// Line 2 : N1 elements for list 1
// Line 3 : N2 the size of list 2
// Line 4 : N2 elements for list 2

// Constraints
// 1 <= T <= 1000
// 0<= N1, N2 <= 10^6
// -10^7 <= Ai <= 10^7

// Output Format
// For each testcase , print the node data of merged linked list.

// Sample Input
// 1
// 4
// 1 3 5 7
// 3
// 2 4 6
// Sample Output
// 1 2 3 4 5 6 7
// Explanation
// The two lists after merging give the sorted output as [1,2,3,4,5,6,7] .

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int key)
    {
        data = key;
        next = NULL;
    }

};

class list
{

public:
    node *head;
    node *tail;

    list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int key)
    {
        node *n = new node(key);

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }

    }

    void print()
    {
        node * temp;
        temp=head;
        while (temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        
    }
};
// void merge(list &a,list b)
// {
//   node * t1,*t2;

//   t2=a.head;
 

//   if (a.head->data> b.head->data)
//   {
//       a.head=b.head;
//       b.head=b.head->next;
//       a.head->next=t2;
//   }
//   t1=a.head;


//   while (t2 && b.head)
//   {
//      if (t2->data > b.head->data)
//      {
//         t1->next=b.head;
        
//         b.head=b.head->next;
//         t1->next->next=t2;
//          t1=t1->next;

//      }
   
//       else
//       {
//         t1=t2;
//           t2=t2->next;
//       }
//   }
  
//   if (b.head)
//   {
//       t2->next=b.head;
//       a.tail=b.tail;
//       b.head=NULL;
//       b.tail=NULL;
//   }



  
  

// }






node* merge(node *a,node *b){
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node *c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}


int main()
{


    


    int t, n,m,key;
    cin>>t;


    while (t--)
    {
        list a,b;
        cin>>n;

        for (int i = 0; i < n; i++)
        {
            cin>>key;
            a.insert(key);

        }
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>key;
            b.insert(key);
        }

       a.head= merge(a.head,b.head);
        a.print();

        delete &a;
        delete &b;
        
    }
    
}