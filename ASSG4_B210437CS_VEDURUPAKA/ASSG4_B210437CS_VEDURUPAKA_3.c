#include <stdio.h>
void swap(float *a,float *b){
    float t=*a;
    *a=*b;
    *b=t;
}
void MAX_HEAPIFY(float a[],int n,int i){
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if(l<n && a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(&a[i],&a[largest]);
        MAX_HEAPIFY(a,n,largest);
    }
}
void BUILD_MAX_HEAP(float a[],int n)
{
    int i;
    for(i=(n-1)/2;i>=0;i--){
        MAX_HEAPIFY(a,n,i);
    }
}
void HEAPSORT(float a[],int n){
    BUILD_MAX_HEAP(a,n);
    swap(&a[0],&a[n-1]);
}
int main()
{
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    float a[n];
    for(i=0;i<n;i++){
        scanf("%f",&a[i]);
    }
    float b[k];
    for(i=0;i<(n/k);i++)
    {
        for(j=0;j<k;j++)
        {
            b[j]=a[j+(k*i)];
        }
        HEAPSORT(b,k);
        printf("%.2f ",b[k-1]);
    }
    return 0;
}
