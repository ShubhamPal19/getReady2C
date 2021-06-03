// check whether Link list has cycle or not


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




bool iscyclic(node * head)
{
    node * sptr=head,*fptr=head->next;
    while (fptr!=NULL && fptr->next!=NULL)
    {
        fptr=fptr->next->next;
        sptr=sptr->next;
        if (sptr==fptr)
        {
            return true;
        }
        
    }

    return false;
    
}



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


void creatcycle(node *head , int n)
{

    while (n && head->next!=NULL)  
    {

        
        head=head->next;
        n--;
        
    }
    if (n)
    {
       
        cout<<"Cant form cycle at this node"<<endl;
        return;
    }
    
    
    node * temp=head;

    while (temp->next!=NULL)
    {
        
       temp=temp->next;
    }
    temp->next=head;
    
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
    
    if (iscyclic(head))
    {
        cout<<"Yes,given linklist is cyclic."<<endl;
    }
    else    
     cout <<"not cyclic."<<endl;
    
    creatcycle(head,4);

    if (iscyclic(head))
    {
        cout<<"Yes, linklist is cyclic."<<endl;
    }
    else    
     cout <<"Not cyclic."<<endl;


}









