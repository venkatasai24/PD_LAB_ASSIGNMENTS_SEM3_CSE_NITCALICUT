#include<stdio.h>
#include<stdlib.h>
struct stack
{
  int top;
  int e[1000];
};
int EVALUATEPOSTFIX(char p[]) {
  struct stack k;
  k.top=-1;
  int i,r,num;
  int a,b;
  for(i=0;p[i]!='\0';i++)
  {
    if (p[i]==' ')
    {
      continue;
    }
    else if(p[i]>='0' && p[i]<='9')
    {
      num=0;
      while(p[i]>='0' && p[i]<='9')
      {
        num=(num*10)+(int)(p[i]-'0');
        i++;
      }
      i--;
      k.top++;
      k.e[k.top]=num;
    }
    else
    {
      b=k.e[k.top];
      k.top--;
      a=k.e[k.top];
      k.top--;
      switch(p[i])
      {
        case('+'):
        r=a+b;
        break;
        case('-'):
        r=a-b;
        break;
        case('*'):
        r=a*b;
        break;
        case('/'):
        r=a/b;
        break;
      }
      k.top++;
      k.e[k.top]=r;
    }
  }
  int ans = k.e[k.top];
  k.top--;
  return ans;
}
int main() {
  int t,i;
  char c[1000];
  scanf("%d",&t);
  int *arr;
  arr = (int*)malloc(sizeof(int)*t);
  i=0;
  while (i<t)
  {
    scanf("\n%[^\n]",c);
    arr[i]=EVALUATEPOSTFIX(c);
    ++i;
  }
  for(i=0; i<t;++i)
  {
    printf("%d\n",arr[i]);
  }
  return 0;
}
