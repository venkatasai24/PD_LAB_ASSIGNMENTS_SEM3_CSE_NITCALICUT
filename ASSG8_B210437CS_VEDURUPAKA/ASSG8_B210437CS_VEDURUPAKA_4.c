#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct stack
{
  int top;
  char a[100];
};
typedef struct node* Node;
Node CREATE_NODE(int value)
{
  Node n=(Node)malloc(sizeof(struct node));
  n->data=value;
  n->left=NULL;
  n->right=NULL;
  return n;
}
void PUSH(struct stack* s,char c)
{
  if((s->top)!=99)
  {
    (s->top)++;
    s->a[s->top]=c;
  }
}
void POP(struct stack* s)
{
  if((s->top)!=-1)
  {
    (s->top)--;
  }
}
int FIND_BRACKET(char c[],int l,int r)
{
  struct stack* s;
  (s->top)=-1;
  for(int i=l;i<=r;i++)
  {
    if(c[i]=='(')  PUSH(s,c[i]);
    else if(c[i]==')')
      if(s->a[s->top]=='(') POP(s);
        if((s->top)==-1)  return i;
  }
  return -1;
}
Node BUILD_TREE(char c[],int s,int e)
{
  if(s>e)  return NULL;
  int num=0;
  while(s<=e && c[s]>='0' && c[s]<='9')
  {
    num = (num*10) + (c[s]-48);
    s++;
  }
  Node root=CREATE_NODE(num);
  int index=-1;
  if(s<=e && c[s]=='(')
  {
    index=FIND_BRACKET(c,s,e);
  }
  if(index!=-1)
  {
    root->left=BUILD_TREE(c,s+1,index-1);
    root->right=BUILD_TREE(c,index+2,e-1);
  }
  return root;
}
void POSTORDER(Node root)
{
  if(root!=NULL)
  {
    POSTORDER(root->left);
    POSTORDER(root->right);
    printf("%d ",root->data);
  }
}
int main()
{
  char c[1000];
  scanf("%[^\n]s",c);
  char b[1000];
  int i,k=0;
  for(i=0;c[i]!='\0';i++)
  {
    if(c[i]!=' ')  b[k++]=c[i];
  }
  Node root=BUILD_TREE(b,1,k-2);
  POSTORDER(root);
  return 0;
}
