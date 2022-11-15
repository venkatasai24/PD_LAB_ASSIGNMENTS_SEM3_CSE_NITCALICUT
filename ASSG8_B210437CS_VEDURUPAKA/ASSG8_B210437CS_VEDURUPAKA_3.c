#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
char c[1000];
int i=0;
typedef struct node* Node;
Node CREATE_NODE(int value)
{
    Node n=(Node)malloc(sizeof(struct node));
    n->data=value;
    n->left=NULL;
    n->right=NULL;
    return (n);
}
Node INSERT(Node root,int value)
{
  if(root==NULL)  return (CREATE_NODE(value));
  else
  {
    if(root->data < value) root->right=INSERT(root->right,value);
    else  root->left=INSERT(root->left,value);
    return (root);
  }
}
void TREE_TO_STR(Node root)
{
    if(root==NULL)  return;
    c[i++]=(root->data)+'0';
    c[i++]='(';
    TREE_TO_STR(root->left);
    c[i++]=')';
    c[i++]='(';
    TREE_TO_STR(root->right);
    c[i++]=')';
}
int main()
{
    Node root=NULL;
    char ch;
    int a,j,k;
    char b[1000];
    scanf("%c",&ch);
    while(ch!='e')
    {
        switch(ch)
        {
            case('i'):
            scanf("%d",&a);
            root=INSERT(root,a);
            break;
            case('p'):
            TREE_TO_STR(root);
            printf("( ");
            if(i!=0)
            {
                k=0;
                for(j=0;j<i;j++)
                {
                    if(c[j]!=' ')
                    {
                        b[k++]=c[j];
                    }
                }
                for(j=0;j<k;j++)
                {
                    printf("%c ",b[j]);
                }
            }
            printf(")\n");
            i=0;
            break;
        }
        scanf("%c",&ch);
    }
    return 0;
}
