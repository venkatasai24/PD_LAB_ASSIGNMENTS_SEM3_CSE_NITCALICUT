#include<stdio.h>
#include<stdlib.h>
struct L
{
    int data;
    struct L* next;
    struct L* prev;
};
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
    new->prev=0;
    new->next=0;
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
        struct L* temp=(*head);
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
}
int LINEAR_SEARCH(struct L** head,int x)
{
    int length=1;
    struct L* temp=(*head);
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
void LIST_INSERT_AFTER(struct L** head,int x,int y)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        struct L* temp=(*head);
        int pos=LINEAR_SEARCH(head,y);
        if(pos==0)
        {
            printf("ABSENT\n");
        }
        else if(pos==LENGTH(head))
        {
            LIST_INSERT_TAIL(head,x);
        }
        else
        {
            while(temp->data!=y)
            {
              temp=temp->next;
            }
            struct L* new=CREATE_NODE(new,x);
            struct L* prevnode=temp->next;
            new->prev=temp;
            new->next=prevnode;
            temp->next=new;
            prevnode->prev=new;
        }
    }
}
void LIST_INSERT_BEFORE(struct L** head,int x,int y)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        struct L* temp=(*head);
        int pos=LINEAR_SEARCH(head,y);
        if(pos==0)
        {
            printf("ABSENT\n");
        }
        else if(pos==1)
        {
            LIST_INSERT_FRONT(head,x);
        }
        else
        {
            while(temp->data!=y)
            {
              temp=temp->next;
            }
            struct L* new=CREATE_NODE(new,y);
            temp->data=x;
            struct L* prevnode=temp->next;
            new->prev=temp;
            new->next=prevnode;
            temp->next=new;
            prevnode->prev=new;
        }
    }
}
void LIST_DELETE_FIRST(struct L** head)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        struct L* temp=(*head);
        if(LENGTH(head)==1)
        {
            printf("FIRST\n");
        }
        else
        {
          printf("%d\n",(*head)->data);
        }
        (*head)=(*head)->next;
        free(temp);
    }
}
void LIST_DELETE_LAST_AND_PRINT(struct L** head)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        struct L* temp=(*head);
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        if(temp->prev!=0)
        {
           struct L* prevnode=temp->prev;
           prevnode->next=NULL;
           printf("%d\n",prevnode->data);
        }
        free(temp);
    }
}
void LIST_DELETE_LAST(struct L** head)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        struct L* temp=(*head);
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        printf("%d\n",temp->data);
        struct L* prevnode=temp->prev;
        prevnode->next=NULL;
        free(temp);
    }
}
void LIST_DELETE(struct L** head,int x)
{
   if((*head)==0)
   {
        printf("NULL\n");
   }
   else
   {
       struct L* temp=(*head);
       int pos=LINEAR_SEARCH(head,x);
       if(pos==0)
       {
           printf("ABSENT\n");
       }
       else if(pos==1)
       {
           LIST_DELETE_FIRST(head);
       }
       else if(pos==LENGTH(head))
       {
           LIST_DELETE_LAST_AND_PRINT(head);
       }
       else
       {
           while(temp->data!=x)
           {
                temp=temp->next;
           }
           if(temp->prev!=0)
           {
              printf("%d\n",(temp->prev)->data);
           }
           struct L* nextnode=temp->next;
           struct L* prevnode=temp->prev;
           prevnode->next=temp->next;
           nextnode->prev=temp->prev;
           free(temp);
       }
   }
}
void PRINT_REVERSE(struct L** head,int x)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        int pos=LINEAR_SEARCH(head,x);
        if(pos==0)
        {
            printf("ABSENT\n");
        }
        else
        {
            struct L* temp=(*head);
            while(temp->data!=x)
            {
                temp=temp->next;
            }
            while(temp!=0)
            {
                printf("%d ",temp->data);
                temp=temp->prev;
            }
            printf("\n");
        }
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
    case('a'):
        scanf("%d%d",&x,&y);
        LIST_INSERT_AFTER(&head,x,y);
        break;
    case('b'):
        scanf("%d%d",&x,&y);
        LIST_INSERT_BEFORE(&head,x,y);
        break;
    case('d'):
        scanf("%d",&x);
        LIST_DELETE(&head,x);
        break;
    case('i'):
        LIST_DELETE_FIRST(&head);
        break;
    case('l'):
        LIST_DELETE_LAST(&head);
        break;
    case('r'):
        scanf("%d",&x);
        PRINT_REVERSE(&head,x);
        break;
    }
    scanf("%c",&c);
  }
  return 0;
}
