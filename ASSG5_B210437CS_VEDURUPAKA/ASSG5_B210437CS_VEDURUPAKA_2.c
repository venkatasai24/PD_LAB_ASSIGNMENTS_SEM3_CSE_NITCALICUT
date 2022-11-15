#include<stdio.h>
#include<stdlib.h>
struct L
{
    char data;
    struct L* next;
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
struct L* CREATE_NODE(struct L* new,char x)
{
    new=(struct L*)malloc(sizeof(struct L));
    new->data=x;
    new->next=0;
    return new;
}
void LIST_INSERT_FRONT(struct L** head,char x)
{
    struct L* new=CREATE_NODE(new,x);
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
void LIST_INSERT_TAIL(struct L** head,char x)
{
    struct L* new=CREATE_NODE(new,x);
    if((*head)==0)
    {
        (*head)=new;
    }
    else
    {
        struct L* temp=*head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}
int LINEAR_SEARCH(struct L** head,char x)
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
void LIST_INSERT_AFTER(struct L** head,char x,char y)
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
            struct L* prev=temp->next;
            temp->next=new;
            new->next=prev;
        }
    }
}
void LIST_INSERT_BEFORE(struct L** head,char x,char y)
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
            temp->data=x;
            struct L* new=CREATE_NODE(new,y);
            struct L* prev=temp->next;
            temp->next=new;
            new->next=prev;
        }
    }
}
void LIST_DELETE_FIRST_AND_PRINT(struct L** head)
{
    if((*head)==0)
    {
        printf("NULL\n");
    }
    else
    {
        struct L* temp=(*head);
        if(temp->next!=0)
        {
            printf("%c\n",(temp->next)->data);
        }
        (*head)=(*head)->next;
        free(temp);
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
        printf("%c\n",temp->data);
        (*head)=(*head)->next;
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
        struct L* prev=temp;
        while(temp->next!=0)
        {
            prev=temp;
            temp=temp->next;
        }
        if(LENGTH(head)==1)
        {
            printf("LAST\n");
            *head=0;
        }
        else
        {
           printf("%c\n",temp->data);
        }
        prev->next=NULL;
        free(temp);
    }
}
void LIST_DELETE(struct L** head,char x)
{
   if(LENGTH(head)==0)
   {
       printf("NULL\n");
   }
   else
   {
       struct L* temp=(*head);
       struct L* prev=temp;
       int pos=LINEAR_SEARCH(head,x);
       if(pos==0)
       {
           printf("ABSENT\n");
       }
       else if(pos==LENGTH(head))
       {
           LIST_DELETE_LAST(head);
       }
       else if(pos==1)
       {
           LIST_DELETE_FIRST_AND_PRINT(head);
       }
       else
       {
           while(temp->data!=x)
           {
                prev=temp;
                temp=temp->next;
           }
           if(temp->next!=0)
           {
               printf("%c\n",(temp->next)->data);
           }
           prev->next=temp->next;
           free(temp);
       }
   }
}
void PRINT_LIST(struct L** head)
{
    struct L* temp=(*head);
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
  struct L* head=0;
  char c;
  char x,y;
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
    case('a'):
        scanf(" %c %c",&x,&y);
        LIST_INSERT_AFTER(&head,x,y);
        break;
    case('b'):
        scanf(" %c %c",&x,&y);
        LIST_INSERT_BEFORE(&head,x,y);
        break;
    case('d'):
        scanf(" %c",&x);
        LIST_DELETE(&head,x);
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
