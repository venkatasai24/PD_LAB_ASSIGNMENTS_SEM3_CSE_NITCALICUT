#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* left;
  struct node* right;
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
Node INSERT(Node root,int value)
{
  if(root==NULL)  return CREATE_NODE(value);
  else
  {
    if(root->data < value) root->right=INSERT(root->right,value);
    else  root->left=INSERT(root->left,value);
    return root;
  }
}
Node SEARCH(Node root,int value)
{
  while(root)
  {
    if(root->data==value) return root;
    else if(root->data < value ) root=root->right;
    root=root->left;
  }
  return root;
}
int FIND_MAX(Node root)
{
  Node temp=root;
  while(temp->right)
  {
    temp=temp->right;
  }
  return temp->data;
}
int FIND_MIN(Node root)
{
  Node temp=root;
  while(temp->left)
  {
    temp=temp->left;
  }
  return temp->data;
}
void INORDER(Node root)
{
  if(root!=NULL)
  {
    INORDER(root->left);
    printf("%d ",root->data);
    INORDER(root->right);
  }
}
void PREORDER(Node root)
{
  if(root!=NULL)
  {
    printf("%d ",root->data);
    PREORDER(root->left);
    PREORDER(root->right);
  }
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
  Node root=NULL;
  Node s=NULL;
  char c;
  int a,b;
  scanf("%c",&c);
  while (c!='e') {
    switch (c) {
      case('a'):
      scanf("%d",&a);
      root=INSERT(root,a);
      break;
      case('s'):
      scanf("%d",&a);
      s=SEARCH(root,a);
      if(s==NULL)  printf("NotFound\n");
      else printf("Found\n");
      break;
      case('x'):
      if(root==NULL)  printf("NIL\n");
      else
      {
         b=FIND_MAX(root);
         printf("%d\n",b);
      }
      break;
      case('n'):
      if(root==NULL)  printf("NIL\n");
      else
      {
        b=FIND_MIN(root);
        printf("%d\n",b);
      }
      break;
      case('i'):
      if(root==NULL)  printf("NIL");
      else INORDER(root);
      printf("\n");
      break;
      case('p'):
      if(root==NULL)  printf("NIL");
      else PREORDER(root);
      printf("\n");
      break;
      case('t'):
      if(root==NULL)  printf("NIL");
      else POSTORDER(root);
      printf("\n");
      break;
    }
    scanf("%c",&c);
  }
  return 0;
}
