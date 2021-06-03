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



node* kth_element_from_last(node * head, int k)
{
    node * ptr1=head,* ptr2=head;
    while (k && ptr2!=NULL)
        {
            ptr2=ptr2->next;
            k--;
        }
    if (k)
        return NULL;
    while (ptr2)
    {
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }
    return ptr1;
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
    int i;
    node *n;
        
    cout<<"Enter the value of k : ";
    cin>>i;
   n= kth_element_from_last(head,i);
if (n==NULL)
   cout<<"The number of elements are less than "<<i<<"."<<endl;
    
else 
    cout<<"Element at index " <<i<< " from last is "<< n->data<<endl;

}