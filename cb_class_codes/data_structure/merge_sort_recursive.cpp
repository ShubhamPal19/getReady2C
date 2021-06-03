#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int datum)
    {
        this->data = datum;
        this->next = NULL;
    }
};

int length(node *head)
{
    int l = 0;
    while (head != NULL)
    {
        head = head->next;
        l++;
    }
    return l;
}

void insertatfront(node *&head, node *&tail, int data)
{
    node *n = new node(data);

    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    n->next = head;
    head = n;
}

void insertatend(node *&head, node *&tail, int data)
{

    node *n = new node(data);
    if (head == NULL)
    {
        (head) = n;
        (tail) = n;
    }

    else
    {
        (tail)->next = n;

        (tail) = n;
    }
}

void insertatposition(node *&head, node *&tail, int data, int index)

{
    if (head == NULL || index == 0)
    {
        insertatfront(head, tail, data);
    }
    else if (index >= length(head) - 1)
    {
        insertatend(head, tail, data);
    }

    else
    {

        node *temp, *current, *n = new node(data);
        index--;
        current = head;
        while (index--)
        {
            current = current->next;
        }

        temp = current->next;
        current->next = n;
        n->next = temp;
    }
}



node *find_mid(node *head, int flag) // second argument( flag) is 1 if you want the first mid in linklist having even num of nodes and 0 if you want second mid for even length of linklist.

{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *fastptr, *slowptr;
    fastptr = head->next;
    slowptr = head;
    int flag2 = 0;

    while (fastptr->next != NULL)
    {
        fastptr = fastptr->next->next;
        if (fastptr == NULL)
        {
            flag2 = 1;
            break;
        }
        slowptr = slowptr->next;
    }
    if (flag == 0 || flag2)
    {
        return slowptr->next;
    }
    else
        return slowptr;
}


node * merge(node * head1, node * head2)
{
    if (head1==NULL)
    {
        return head2;
    }
    
    if (head2==NULL)
    {
        return head1;
    }
    
    if (head1->data <head2->data)
    {
     head1->next =merge(head1->next,head2);
     return head1;
    }
    
    else
        head2->next=merge(head1,head2->next);
         return head2;
}

node * mergesort(node * head )
{
    if (head->next==NULL)
    {
        return head;
    }

    node * mid=find_mid(head,1), *head2;
    head2=mid->next;
    mid->next=NULL;

    return merge(mergesort(head),mergesort(head2));
    
}

void printll(node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";

        head = head->next;
    }

    cout << endl;
}

int main()
{
    //     node n1(3);
    //     node n2(32);
    //     n1.next=&n2;
    //    cout  n1.data << " " << (*n1.next).data << endl;

    node *head = NULL, *tail = NULL;

    insertatend(head, tail, 32);
    insertatfront(head, tail, 1);
    insertatfront(head, tail, 31);
    insertatend(head, tail, 3442);
    insertatfront(head, tail, 152);
    insertatend(head, tail, 2);
    insertatfront(head, tail, 11);
    insertatfront(head, tail, 211);
    insertatend(head, tail, 342);
    insertatfront(head, tail, 15222);
    insertatposition(head, tail, 66, 6);
    printll(head);

   head = mergesort(head);
    cout << "After merge sort.\n";
    printll(head);
}