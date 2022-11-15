#include <stdio.h>
void insertionsort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}
void read_and_store(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        A[i]=A[i];
    }
}
void print(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int digit_sum(int n)
{
    int sum=0;
    while(n>0)
    {
        int r=n%10;
        sum+=r;
        n/=10;
    }
    return sum;
}
void digit_sort(int A[],int n)
{
    int i,j,k,l,b[n],c[n];
    for(i=0;i<n;i++)
    {
        b[i]=digit_sum(A[i]);
    }
    insertionsort(b,n);
    for(i=0;i<n;i++)
    {
        k=0;
        for(j=0;j<n;j++)
        {
            if(b[i]==digit_sum(A[j]))
            {
                c[i]=A[j];
                k=j+1;
                break;
            }
        }
        if(k>0)
        {
            for(l=k-1;l<(n-1);l++)
            {
                A[l]=A[l+1];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        A[i]=c[i];
    }
}
int main()
{
    int i,n,index,a[n];
    char in;
    do
    {
        scanf("%c",&in);
        switch(in)
        {
            case('r'):
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            read_and_store(a,n);
            break;
            case('p'):
            print(a,n);
            break;
            case('d'):
            scanf("%d",&index);
            printf("%d\n",digit_sum(a[index]));
            break;
            case('s'):
            digit_sort(a,n);
            break;
            case('t'):
            printf("-1");
            break;
        }
    }
    while(in!='t');
    return 0;
}
