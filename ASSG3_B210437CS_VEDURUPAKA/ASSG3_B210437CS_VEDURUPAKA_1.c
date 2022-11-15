#include <stdio.h>
void insertionsort(float a[],int n)
{
    int i,j;
    float temp;
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
int main()
{
    int i,j,n;
    scanf("%d",&n);
    float a[n];
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    int count=0;
    for(i=0;i<n;i++)
    {
        if(-1000<=a[i] && a[i]<=1000)
        {
            count+=1;
        }
    }
    float b[n];
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    if(1<=n && n<=1000 && count==n)
    {
        insertionsort(a,n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(b[i]==a[j])
                {
                  printf("%d ",j);
                  break;
                }
            }
        }
    }
    return 0;
}
