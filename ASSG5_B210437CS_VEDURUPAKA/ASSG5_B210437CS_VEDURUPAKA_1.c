#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node* next;
};
struct node* CREATE_NODE(struct node *new,char x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->next=0;
    return new;
}
void LIST_INSERT_FRONT(struct node** head,char x)
{
    struct node* new=CREATE_NODE(new,x);
    if((*head)==0)
    {
        (*head)=new;
    }
    else
    {
        new->next=(*head);
        (*head)=new;
    }
}
void LIST_INSERT_TAIL(struct node** head,char x)
{
    struct node* new=CREATE_NODE(new,x);
    if((*head)==0)
    {
        (*head)=new;
    }
    else
    {
        struct node* temp=*head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=0;
    }
}
void LIST_DELETE_FIRST(struct node** head)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        struct node* temp=*head;
        printf("%c\n",temp->data);
        (*head)=(*head)->next;
        free(temp);
    }
}
void LIST_DELETE_LAST(struct node** head)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        struct node* temp=*head;
        struct node* prev=temp;
        while(temp->next!=0)
        {
            prev=temp;
            temp=temp->next;
        }
        printf("%c\n",temp->data);
        prev->next=NULL;
        free(temp);
    }
}
void PRINT_LIST(struct node** head)
{
    struct node* temp=*head;
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        while(temp!=0)
        {
            printf("%c ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
  struct node *head=0;
  char c;
  char x;
  scanf("%c",&c);
  while(1)
  {
    if(c=='e')
    {
        break;
    }
    switch(c)
    {
    case('f'):
        scanf(" %c",&x);
        LIST_INSERT_FRONT(&head,x);
        break;
    case('t'):
        scanf(" %c",&x);
        LIST_INSERT_TAIL(&head,x);
        break;
    case('i'):
        LIST_DELETE_FIRST(&head);
        break;
    case('l'):
        LIST_DELETE_LAST(&head);
        break;
    case('p'):
        PRINT_LIST(&head);
        break;
    }
    scanf("%c",&c);
  }
  return 0;
}
