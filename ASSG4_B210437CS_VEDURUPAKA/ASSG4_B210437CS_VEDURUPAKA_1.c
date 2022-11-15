#include <stdio.h>
int cr_index;
int length(char a[])
{
    int length=0;
    for(int i=0;a[i]!='\0';i++)
    {
        length++;
    }
    return length;
}
int compare(char a[],char b[])
{
    if(length(a)!=length(b))
    {
        return -1;
    }
    else
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
}
struct students
{
    char name[100];
    int score;
};
void swap(struct students* a ,struct students* b)
{
    struct students t=*a;
    *a=*b;
    *b=t;
}
void partition(struct students a[],int lb,int ub)
{
    int pivot=a[cr_index].score;
    int i=lb-1;
    for(int j=lb;j<=ub;j++)
    {
        if(a[j].score<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[cr_index]);
}
void quicksort(struct students a[],int lb,int ub)
{
    if(lb<ub)
    {
        partition(a,lb,ub);
    }
}
int main()
{
    int i,n;
    scanf("%d%*c",&n);
    struct students s[n];
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i].name);
        scanf("%d",&s[i].score);
    }
    char  cr[100];
    scanf("%s",cr);
    for(i=0;i<n;i++)
    {
        if(compare(cr,s[i].name)==0)
        {
            cr_index=i;
            break;
        }
    }
    quicksort(s,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%s ",s[i].name);
    }
    return 0;
}
