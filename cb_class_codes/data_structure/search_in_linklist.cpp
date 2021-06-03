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

    node *key_node = NULL;
    key_node = search(head, 3442);
    if (key_node == NULL)
    {
        cout << "Key not found." << endl;
    }
    else
    {
        cout << "Key " << key_node->data << " found." << endl;
    }

    key_node = recursive_search(head, 43);
    if (key_node == NULL)
    {
        cout << "Key not found." << endl;
    }
    else
    {
        cout << "Key " << key_node->data << " found." << endl;
    }
}
