


#include <stdio.h>
#include <stdlib.h>


struct node 
{
    int key;
    struct node * next,* previous;
    
};



void printlist(struct node * head)
{
    struct node * current;
    current=head;
    while (current!=NULL)
    {
        printf("%d  ",current->key);
        current= current->next;
    } 
}

void swapnode(struct node *current)
{
    struct node * temp;

    temp = current->next;
    temp->previous=current->previous;
    temp->previous->next=temp;
    
    current->next=temp->next;
    current->previous=temp;
    temp->next=current;

    if (current->next==NULL)
    {
        return ;
    }
    else
        current->next->previous=current;
    
}

struct node * bubblesort(struct node * head,int n)
{
    struct node * current , *temp;
    int swap, i;

    while (n>0)
    {

      swap=0;
      int i;
      current=head;
      while(current->next!=NULL)
      {
          if ( current->key > current->next->key)
          {

            if (head==current)
            {   
                
              head=current->next;
              current->next=head->next;
              current->next->previous=current;
              head->previous=NULL;
              head->next=current;
              current->previous=head;
                
            }
            else
             swapnode(current);
            swap=1;
            continue;
            
          }
          current=current->next;
       
      }

      if (!swap)
      {
         return head;
      }

      n--;
    }

    return head;

}


void insert(struct node ** head, struct node ** tail,int key )
{
    struct node * temp;
    temp= (struct node * )malloc(sizeof(struct node));
    temp->next=NULL;
    temp->previous=NULL;
    temp->key=key;
    if (*head==NULL)
    {
       *head=temp;
       *tail=temp;

    }
    else{
        (*tail)->next=temp;
        temp->previous=(*tail);
        (*tail)= temp;
    }
   
}


void main()
{

    struct node * head, * tail, *temp;

    head=NULL;
    tail=NULL;

    int n , i , key;

    printf("Enter the number of elements in link list : ");
    scanf("%d",&n);

    printf("Enter the data : \n");


    for ( i = 0; i < n; i++)
    {
        scanf("%d",&key);
        insert(&head,&tail,key);
    }
    
    printlist(head);
    head =  bubblesort(head,n);
    printlist(head);

    

    
}