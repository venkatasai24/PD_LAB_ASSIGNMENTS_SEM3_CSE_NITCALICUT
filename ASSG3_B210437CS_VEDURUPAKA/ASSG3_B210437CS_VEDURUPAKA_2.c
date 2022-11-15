#include <stdio.h>
int binarysearch(int a[],int l,int r,int t)
{
    if(l<=r)
    {
        int mid=(l+r)/2;
        if(t==a[mid])
        {
            return mid;
        }
        else if(t<a[mid])
        {
            return binarysearch(a,l,mid-1,t);
        }
        else
        {
            return binarysearch(a,mid+1,r,t);
        }
    }
    return -1;
}
void merge(int a[],int l,int mid,int r)
{
    int n1,n2,i,j,k;
    n1=mid-l+1;
    n2=r-mid;
    int left[n1],right[n2];
    for(i=0;i<n1;i++)
    {
        left[i]=a[l+i];
    }
    for(i=0;i<n2;i++)
    {
        right[i]=a[mid+1+i];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
        }
        else
        {
            a[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge(a,l,mid,r);
    }
}
int main()
{
    int i,j,m,n;
    scanf("%d%d",&m,&n);
    int a1[m],a2[n],a[m+n];
    for(i=0;i<m;i++)
    {
        scanf("%d",&a1[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&a2[i]);
    }
    int target;
    scanf("%d",&target);
    int count=0;
    for(i=0;i<m;i++)
    {
        a[i]=a1[i];
    }
    for(i=0;i<n;i++)
    {
        a[m+i]=a2[i];
    }
    for(i=0;i<(m+n);i++)
    {
        if(-1000<=a[i] && a[i]<=1000)
        {
            count+=1;
        }
    }
    if(m>=1 && m<=1000 && 1<=n && n<=1000 && (m+n)==count)
    {
        mergesort(a,0,m+n-1);
        int index=binarysearch(a,0,m+n-1,target);
        printf("%d ",index);
    }
    return 0;
}
