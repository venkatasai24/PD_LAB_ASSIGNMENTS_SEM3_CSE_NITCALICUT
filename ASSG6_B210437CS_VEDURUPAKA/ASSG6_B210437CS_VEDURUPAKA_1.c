#include<stdio.h>
struct stack
{
  int top;
  int e[100000];
};
typedef struct stack* stack;
void PUSH(stack a,int n,int size) {
  if(a->top==size-1)
  {
    printf("Full\n");
  }
  else
  {
    a->top++;
    a->e[a->top]=n;
  }
}
void POP(stack a,int n) {
  for(int i=1;i<=n;i++)
  {
    if(a->top==-1)
    {
      printf("Empty ");
    }
    else
    {
      printf("%d ",a->e[a->top]);
      a->top--;
    }
  }
  printf("\n");
}
void STACK_FULL(stack a,int size) {
  if(a->top==size-1)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
}
void STACK_EMPTY(stack a) {
  if(a->top==-1)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
}
int main(int argc, char const *argv[]) {
  stack s;
  s->top=-1;
  int size,num;
  scanf("%d",&size);
  char c;
  scanf("%c",&c);
  while(c!='t')
  {
    switch (c) {
      case('i'):
      scanf("%d",&num);
      PUSH(s,num,size);
      break;
      case('d'):
      scanf("%d",&num);
      POP(s,num);
      break;
      case('f'):
      STACK_FULL(s,size);
      break;
      case('e'):
      STACK_EMPTY(s);
      break;
    }
    scanf("%c",&c);
  }
  return 0;
}
