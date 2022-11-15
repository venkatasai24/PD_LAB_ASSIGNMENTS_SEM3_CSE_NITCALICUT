#include<stdio.h>
#include<stdlib.h>
struct node
{
  char data;
  struct node* left;
  struct node* right;
};
typedef struct node* node;
struct stack
{
  int top;
  node *a;
};
typedef struct stack* stack;
void PUSH(stack s,struct node* d)
{
  ++s->top;
  s->a[s->top]=d;
}
struct node* POP(stack s)
{
  struct node* d=s->a[s->top];
  --s->top;
  return d;
}
struct node* CREATE_NODE(char x)
{
  struct node* d=(struct node*)malloc(sizeof(struct node));
  d->data=x;
  d->left=NULL;
  d->right=NULL;
  return d;
}
struct node* CONSTRUCT_TREE(char p[])
{
  int i;
  struct node *r,*a,*b;
  stack s;
  s = (stack)malloc(sizeof(struct stack));
  s->a = (node*)malloc(sizeof(node)*1000);
  s->top = -1;
  for(i=0;p[i]!='\0';i++)
  {
    if(p[i]=='+' || p[i]=='-' || p[i]=='*' || p[i]=='/')
    {
      r=CREATE_NODE(p[i]);
      b=POP(s);
      a=POP(s);
      r->left=a;
      r->right=b;
      PUSH(s,r);
    }
    else
    {
      r=CREATE_NODE(p[i]);
      PUSH(s,r);
    }
  }
  return s->a[s->top];
}
void INORDER(struct node* r)
{
  if(r==NULL)
  {
    return;
  }
  INORDER(r->left);
  printf("%c",r->data);
  INORDER(r->right);
}
void PREORDER(struct node* r)
{
  if(r==NULL)
  {
    return;
  }
  printf("%c",r->data);
  PREORDER(r->left);
  PREORDER(r->right);
}
void POSTORDER(struct node* r)
{
  if(r==NULL)
  {
    return;
  }
  POSTORDER(r->left);
  POSTORDER(r->right);
  printf("%c",r->data);
}
int main()
{
  struct node* root=NULL;
  char c;
  char d[100];
  scanf("%c",&c);
  while(c!='t')
  {
    switch (c) {
      case('e'):
      scanf("%s",d);
      root = CONSTRUCT_TREE(d);
      break;
      case('i'):
      INORDER(root);
      printf("\n");
      break;
      case('p'):
      PREORDER(root);
      printf("\n");
      break;
      case('s'):
      POSTORDER(root);
      printf("\n");
      break;
    }
    scanf("%c",&c);
  }
  return 0;
}
