#include<stdio.h>
struct stack
{
  int top;
  char e[10000];
};
int PRECEDENCE(char a)
{
  if(a=='^')
  {
    return 3;
  }
  if(a=='*' || a=='/')
  {
    return 2;
  }
  if(a=='+' || a=='-')
  {
    return 1;
  }
  return 0;
}
void INFIX_TO_POSTFIX(char p[]) {
  char s[10000];
  int i,j=0;
  struct stack k;
  k.top=-1;
  for(i=0;p[i]!='\0';i++)
  {
    if (p[i]!='^' && p[i]!='+' && p[i]!='-' && p[i]!='*' && p[i]!='/' && p[i]!='(' && p[i]!=')')
    {
      s[j]=p[i];
      j++;
    }
    else
    {
      if(k.top==-1)
      {
        k.top++;
        k.e[k.top]=p[i];
      }
      else if(p[i]=='(')
      {
        k.top++;
        k.e[k.top]=p[i];
      }
      else if (p[i]==')') {
        while(k.e[k.top]!='(')
        {
          s[j]=k.e[k.top];
          j++;
          k.top--;
        }
        k.top--;
      }
      else
      {
        if(PRECEDENCE(k.e[k.top])==3 && PRECEDENCE(p[i])==3)
        {
          k.top++;
          k.e[k.top]=p[i];
        }
        else
        {
          while(k.top!=-1 && PRECEDENCE(k.e[k.top])>=PRECEDENCE(p[i]))
          {
            s[j]=k.e[k.top];
            j++;
            k.top--;
          }
            k.top++;
            k.e[k.top]=p[i];
        }
      }
    }
  }
  while(k.top!=-1)
  {
    s[j]=k.e[k.top];
    j++;
    k.top--;
  }
  s[j]='\0';
  for(i=0;s[i]!='\0';i++)
  {
    printf("%c",s[i]);
  }
  printf("\n");
}
int main(int argc, char const *argv[]) {
  int t;
  char c[10000];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",c);
    INFIX_TO_POSTFIX(c);
  }
  return 0;
}
