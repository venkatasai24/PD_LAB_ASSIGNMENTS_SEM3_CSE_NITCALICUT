#include<stdio.h>
#include<stdlib.h>
struct queue
{
  int data;
  struct queue* next;
};
struct queue* CREATE_NODE(struct queue* a,int n)
{
  a=(struct queue*)malloc(sizeof(struct queue));
  a->data=n;
  a->next=NULL;
  return a;
}
void ENQUEUE(struct queue** a,struct queue** b,int n) {
  struct queue *s=CREATE_NODE(s,n);
  if(*a==NULL && *b==NULL)
  {
    *a=s;
    *b=s;
  }
  else
  {
    (*b)->next=s;
    *b=s;
  }
}
void DEQUEUE(struct queue** a,struct queue** b,int n) {
  for(int i=1;i<=n;i++)
  {
    if(*a==NULL && *b==NULL)
    {
      printf("Empty ");
    }
    else if (*a==*b) {
      struct queue *temp=*a;
      printf("%d ",temp->data);
      *a=NULL;
      *b=NULL;
      free(temp);
    }
    else
    {
      struct queue *temp=*a;
      printf("%d ",temp->data);
      *a=(*a)->next;
      free(temp);
    }
  }
  printf("\n");
}
void QUEUE_EMPTY(struct queue** a,struct queue** b) {
  if(*a==NULL && *b==NULL)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
}
int main(int argc, char const *argv[]) {
  struct queue *h=NULL;
  struct queue *t=NULL;
  int num;
  char c;
  scanf("%c",&c);
  while(c!='t')
  {
    switch (c) {
      case('i'):
      scanf("%d",&num);
      ENQUEUE(&h,&t,num);
      break;
      case('d'):
      scanf("%d",&num);
      DEQUEUE(&h,&t,num);
      break;
      case('e'):
      QUEUE_EMPTY(&h,&t);
      break;
    }
    scanf("%c",&c);
  }
  return 0;
}
