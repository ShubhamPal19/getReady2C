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

            cout << " heal" << endl;
            current = current->next;
        }

        temp = current->next;
        current->next = n;
        n->next = temp;
    }
}

// deletion at front;
void deleteatfront(node *&head, node *&tail)
{

    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *n = head;
        head = head->next;
        delete n;
    }
}

void deleteatend(node *&head, node *&tail)
{

    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    else
    {
        node *current;
        current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        current->next = NULL;
        tail = current;
        delete tail->next;
    }
}

void deleteatindex(node *&head, node *&tail, int index)
{
    if (index == 0)
    {
        deleteatfront(head, tail);
    }
    else if (index >= length(head))
    {
        deleteatend(head, tail);
    }

    else
    {
        node *current = head, *temp = NULL;
        index--;

        while (index--)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

node *search(node *head, int key)
{

    while (head != NULL)
    {
        if (head->data == key)
        {
            return head;
        }
        head = head->next;
    }
}

node *recursive_search(node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == key)
    {
        return head;
    }
    return recursive_search(head->next, key);
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

void reverse(node *&head, node *&tail)
{
    // if (head == tail)
    // {
    //     return;
    // }
    // tail = head;

    // tail = head;

    // do
    // {
    //     current->next = previous;
    //     previous = current;
    //     temp = current->next;

    // } while (temp != NULL);

    // current->next = previous;
    // head = current;
    
    tail=head;
node * current=head, *previous=NULL,* temp=NULL;

while (current)
{
    temp=current->next;
    current->next=previous;
    previous=current;
    current=temp;
}
head=previous;
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
    insertatposition(head, tail, 6666, 886);
    printll(head);

    reverse(head, tail);
    printll(head);
}
