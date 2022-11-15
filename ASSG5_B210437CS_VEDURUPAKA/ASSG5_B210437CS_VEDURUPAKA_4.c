#include<stdio.h>
#include<stdlib.h>
struct L
{
    int data;
    struct L* next;
    struct L* prev;
};
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int LENGTH(struct L** head)
{
    int length=0;
    struct L* temp=(*head);
    while(temp!=0)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
struct L* CREATE_NODE(struct L* new,int x)
{
    new=(struct L*)malloc(sizeof(struct L));
    new->data=x;
    return new;
}
void LIST_INSERT_FRONT(struct L** head,int x)
{
    struct L* new=CREATE_NODE(new,x);
    if((*head)==0)
    {
        (*head)=new;
    }
    else
    {
        new->next=(*head);
        (*head)->prev=new;
        (*head)=new;
    }
}
void LIST_INSERT_TAIL(struct L** head,int x)
{
    struct L* new=CREATE_NODE(new,x);
    if((*head)==0)
    {
        (*head)=new;
    }
    else
    {
        struct L*temp=(*head);
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
        new->next=0;
    }
}
int LINEAR_SEARCH(struct L** head,int x)
{
    int length=1;
    struct L* temp=head;
    while(temp!=0)
    {
        if(temp->data==x)
        {
            return length;
        }
        temp=temp->next;
        length++;
    }
    return 0;
}
void PRINT_LIST(struct L** head,int x,int y)
{
    if(x>LENGTH(head) || y>LENGTH(head))
    {
        printf("NULL\n");
    }
    else
    {
       struct L* temp1=(*head);
       int i=1;
       while(i<x)
       {
           temp1=temp1->next;
           i++;
       }
       struct L* tail=(*head);
       while(tail->next!=0)
       {
           tail=tail->next;
       }
       struct L* temp2=tail;
       int j=1;
       while(j<y)
       {
           temp2=temp2->prev;
           j++;
       }
       swap(&(temp1->data),&(temp2->data));
       temp2=tail;
       while(temp2!=(*head))
       {
           printf("%d ",temp2->data);
           temp2=temp2->prev;
       }
       printf("%d\n",temp2->data);
    }
}
int main()
{
  struct L* head=0;
  char c;
  int x,y;
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
        scanf("%d",&x);
        LIST_INSERT_FRONT(&head,x);
        break;
    case('t'):
        scanf("%d",&x);
        LIST_INSERT_TAIL(&head,x);
        break;
    case('p'):
        scanf("%d%d",&x,&y);
        PRINT_LIST(&head,x,y);
        break;
    }
    scanf("%c",&c);
  }
  return 0;
}
