#include <stdio.h>
int k=0;
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
    if(l<n)
    {
        k++;
    }
    if(l<n && a[l]>a[largest])
    {
        largest=l;
    }
    if(r<n)
    {
        k++;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        MAX_HEAPIFY(a,n,largest);
    }
}
void BUILD_MAX_HEAP(int a[],int n)
{
    for(int i=(n-1)/2;i>=0;i--)
    {
        MAX_HEAPIFY(a,n,i);
    }
}
void HEAPSORT(int a[],int n)
{
    int i;
    BUILD_MAX_HEAP(a,n);
    for(i=(n-1);i>=0;i--)
    {
        swap(&a[0],&a[i]);
        MAX_HEAPIFY(a,i,0);
    }
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    HEAPSORT(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n%d",k);
    return 0;
}
