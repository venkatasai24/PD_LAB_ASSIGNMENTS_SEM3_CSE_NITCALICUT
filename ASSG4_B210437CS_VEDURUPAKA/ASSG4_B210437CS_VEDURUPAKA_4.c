#include <stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void MAX_HEAPIFY(int a[],int n,int i)
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
    int size, i,p,q,s,j,k,l=0,m,count;
    scanf("%d", &size);
     int arr[size], freq[size];
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }
    scanf("%d",&k);
    for(i=0; i<size; i++)
    {
        count = 1;
        for(j=i+1; j<size; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }
        if(freq[i] != 0)
        {
            freq[i] = count;
            l++;
        }
    }
    int b[l];
    int n=0;
    for(i=0; i<size; i++)
    {
        if(freq[i] != 0)
        {
          b[n]=freq[i];
          n++;
        }
    }
    HEAPSORT(b,l);
    for(i=0;i<k;i++)
    {
      for(m=0;m<size;m++)
      {
          s=arr[m];
      count=0;
      for(j=0;j<size;j++)
      {
        if(s==arr[j])
        {
            count+=1;
        }
      }
      if(count==b[i])
      {
          printf("%d ",s);
           for(p=0;p<size;p++){
                   if(s==arr[p]){
                    for(q=p;q<(size-1);q++){
                        arr[q]=arr[q+1];
                    }
                    size=size-1;
                }
            }
      }
      }
    }
    return 0;
}