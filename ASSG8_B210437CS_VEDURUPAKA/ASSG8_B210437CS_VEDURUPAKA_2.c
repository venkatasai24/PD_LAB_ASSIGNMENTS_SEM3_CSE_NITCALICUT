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
Node SEARCH(Node root,int value)
{
  if(root==NULL || root->data==value)  return root;
  if(root->data < value) return SEARCH(root->right,value);
  return SEARCH(root->left,value);
}
Node INSERT(Node root,int value)
{
  if(root==NULL)  return CREATE_NODE(value);
  if(root->data < value) root->right=INSERT(root->right,value);
  else  root->left=INSERT(root->left,value);
  return root;
}
Node FIND_MAX(Node root)
{
  Node temp=root;
  while(temp->right)
  {
    temp=temp->right;
  }
  return temp;
}
Node FIND_MIN(Node root)
{
  Node temp=root;
  while(temp->left)
  {
    temp=temp->left;
  }
  return temp;
}
Node DELETE(Node root,int value)
{
  if(root==NULL)  return root;
  if(root->data < value) root->right=DELETE(root->right,value);
  else if(root->data > value) root->left=DELETE(root->left,value);
  else
  {
    if(root->left==NULL && root->right==NULL)
    {
      return NULL;
    }
    else if (root->right==NULL) {
      Node temp=root->left;
      free(root);
      return temp;
    }
    else if (root->left==NULL) {
      Node temp=root->right;
      free(root);
      return temp;
    }
    Node temp=FIND_MIN(root->right);
    root->data=temp->data;
    root->right=DELETE(root->right,temp->data);
  }
  return root;
}
Node PREDECESSOR(Node root,int value)
{
  if(FIND_MIN(root)->data==value)  return NULL;
  Node R=SEARCH(root,value);
  if(R->left!=NULL)
  {
    Node temp=FIND_MAX(R->left);
    return temp;
  }
  Node pred;
  while(root)
  {
    if(root->data > value)
    {
      root=root->left;
    }
    else if (root->data < value)
    {
      pred=root;
      root=root->right;
    }
    else
    {
      break;
    }
  }
  return pred;
}
Node SUCCESSOR(Node root,int value)
{
  if(FIND_MAX(root)->data==value)  return NULL;
  Node R=SEARCH(root,value);
  if(R->right!=NULL)
  {
    Node temp=FIND_MIN(R->right);
    return temp;
  }
  Node succ;
  while(root)
  {
    if(root->data > value)
    {
      succ=root;
      root=root->left;
    }
    else if (root->data < value)
    {
      root=root->right;
    }
    else
    {
      break;
    }
  }
  return succ;
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
int main()
{
  Node s=NULL;
  Node root=NULL;
  char c;
  int a,b;
  scanf("%c",&c);
  while (c!='e') {
    switch (c) {
      case('a'):
      scanf("%d",&a);
      root=INSERT(root,a);
      break;
      case('d'):
      scanf("%d",&a);
      if(SEARCH(root,a)==NULL) printf("NotFound\n");
      else
      {
        s=DELETE(root,a);
        if(s) printf("%d\n",a);
      }
      break;
      case('c'):
      scanf("%d",&a);
      s=SUCCESSOR(root,a);
      if(s==NULL)  printf("NotFound\n");
      else printf("%d\n",s->data);
      break;
      case('r'):
      scanf("%d",&a);
      s=PREDECESSOR(root,a);
      if(s==NULL)  printf("NotFound\n");
      else printf("%d\n",s->data);
      break;
      case('p'):
      if(root==NULL)  printf("NIL");
      else PREORDER(root);
      printf("\n");
      break;
    }
    scanf("%c",&c);
  }
  return 0;
}
