#include<stdio.h>
#include<stdlib.h>
struct stack
{
  int data;
  struct stack* next;
};
struct stack* CREATE_NODE(struct stack* a,int n)
{
  a=(struct stack*)malloc(sizeof(struct stack));
  a->data=n;
  a->next=NULL;
  return a;
}
void PUSH(struct stack** a,int n) {
  struct stack *s=CREATE_NODE(s,n);
  if(*a==NULL)
  {
    *a=s;
  }
  else
  {
    s->next=*a;
    *a=s;
  }
}
void POP(struct stack** a,int n) {
  for(int i=1;i<=n;i++)
  {
    if(*a==NULL)
    {
      printf("Empty ");
    }
    else
    {
      struct stack *temp=*a;
      printf("%d ",temp->data);
      *a=(*a)->next;
      free(temp);
    }
  }
  printf("\n");
}
void STACK_EMPTY(struct stack** a) {
  if(*a==NULL)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
}
int main(int argc, char const *argv[]) {
  struct stack *s=NULL;
  int num;
  char c;
  scanf("%c",&c);
  while(c!='t')
  {
    switch (c) {
      case('i'):
      scanf("%d",&num);
      PUSH(&s,num);
      break;
      case('d'):
      scanf("%d",&num);
      POP(&s,num);
      break;
      case('e'):
      STACK_EMPTY(&s);
      break;
    }
    scanf("%c",&c);
  }
  return 0;
}
