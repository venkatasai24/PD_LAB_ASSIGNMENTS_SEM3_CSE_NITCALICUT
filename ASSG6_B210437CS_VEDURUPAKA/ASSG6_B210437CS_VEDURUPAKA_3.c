#include<stdio.h>
struct queue
{
  int front;
  int rear;
  int e[100000];
};
void ENQUEUE(struct queue *a,int n,int size) {
  if (a->front==-1 && a->rear==-1) {
    a->front=a->rear=0;
    a->e[a->rear]=n;
  }
  else
  {
    a->rear=(a->rear+1)%size;
    a->e[a->rear]=n;
  }
  if(a->front==(a->rear+1)%size)
  {
    printf("Full\n");
  }
}
void DEQUEUE(struct queue *a,int n,int size) {
  for(int i=1;i<=n;i++)
  {
    if(a->front==-1 && a->rear==-1)
    {
      printf("Empty ");
    }
    else if(a->front==a->rear) {
      printf("%d ",a->e[a->front]);
      a->front=a->rear=-1;
    }
    else
    {
      printf("%d ",a->e[a->front]);
      a->front=(a->front+1)%size;
    }
  }
  printf("\n");
}
void QUEUE_FULL(struct queue *a,int size) {
  if(a->front==(a->rear+1)%size)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
}
void QUEUE_EMPTY(struct queue *a) {
  if(a->front==-1 && a->rear==-1)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
}
int main(int argc, char const *argv[]) {
  struct queue *s;
  s->front=-1;
  s->rear=-1;
  int size,num;
  scanf("%d",&size);
  char c;
  scanf("%c",&c);
  while(c!='t')
  {
    switch (c) {
      case('i'):
      scanf("%d",&num);
      if(s->front==(s->rear+1)%size)
      {
        printf("Full\n");
      }
      else
      {
        ENQUEUE(s,num,size);
      }
      break;
      case('d'):
      scanf("%d",&num);
      DEQUEUE(s,num,size);
      break;
      case('f'):
      QUEUE_FULL(s,size);
      break;
      case('e'):
      QUEUE_EMPTY(s);
      break;
    }
    scanf("%c",&c);
  }
  return 0;
}
