#include <stdio.h>
void copy(char a[],char b[])
{
    int i;
    for(i=0;b[i]!='\0';i++)
    {
        a[i]=b[i];
    }
    a[i]='\0';
}
int compare(char a[],char b[])
{
    int i=0;
    while(a[i]!='\0' && b[i]!='\0')
    {
        if(a[i]<b[i])
        {
            return -1;
        }
        if(a[i]>b[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}
void merge(char a[][100],int l,int mid,int r)
{
    int n1,n2,i,j,k;
    n1=mid-l+1;
    n2=r-mid;
    char left[n1][100],right[n2][100];
    for(i=0;i<n1;i++)
    {
        copy(left[i],a[l+i]);
    }
    for(i=0;i<n2;i++)
    {
        copy(right[i],a[mid+1+i]);
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(compare(left[i],right[j])<=0)
        {
            copy(a[k],left[i]);
            i++;
        }
        else
        {
            copy(a[k],right[j]);
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        copy(a[k],left[i]);
        i++;
        k++;
    }
    while(j<n2)
    {
        copy(a[k],right[j]);
        j++;
        k++;
    }
}
void mergesort(char a[][100],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int i,n;
    scanf("%d%*c",&n);
    char a[n][100];
    for(i=0;i<n;i++)
    {
        fgets(a[i],100,stdin);
    }
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%s",a[i]);
    }
    return 0;
}
