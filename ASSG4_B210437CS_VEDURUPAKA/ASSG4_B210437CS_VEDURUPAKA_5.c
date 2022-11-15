#include <stdio.h>
int size=0;
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void MAX_HEAPIFY(int *a,int n,int i)
{
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if(l<n && a[l]<a[largest])
    {
        largest=l;
    }
    if(r<n && a[r]<a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        MAX_HEAPIFY(a,n,largest);
    }
}
void HEAPSORT(int a[],int n)
{
    int i;
    for(i=(n-1)/2;i>=0;i--)
    {
        MAX_HEAPIFY(a,n,i);
    }
}
void INSERT_PROCESS(int a[],int k)
{
   size+=1;
   a[size-1]=k;
}
void EXTRACT_NEXT_PROCESS(int a[])
{
  if(size>0)
  {
      HEAPSORT(a,size);
      swap(&a[0],&a[size-1]);
      MAX_HEAPIFY(a,size-1,0);
      printf("%d\n",a[size-1]);
      size-=1;
  }
  else
  {
      printf("-1\n");
  }
}
void GET_NEXT_PROCESS(int a[])
{
    if(size>0)
  {
      HEAPSORT(a,size);
      printf("%d\n",a[0]);
  }
}
void CHANGE_PRIORITY(int a[],int k,int x)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(a[i]==k)
        {
            a[i]=x;
            HEAPSORT(a,size);
            break;
        }
    }
}
void DISPLAY_QUEUE(int a[])
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int key,k,x,Q[size];
    char in;
    do
    {
        scanf("%c",&in);
        switch(in)
        {
            case('i'):
            scanf("%d",&key);
            INSERT_PROCESS(Q,key);
            break;
            case('e'):
            EXTRACT_NEXT_PROCESS(Q);
            break;
            case('m'):
            GET_NEXT_PROCESS(Q);
            break;
            case('c'):
            scanf("%d%d",&k,&x);
            CHANGE_PRIORITY(Q,k,x);
            break;
            case('d'):
            DISPLAY_QUEUE(Q);
            break;
        }
    }
    while(in!='s');
    return 0;
}
