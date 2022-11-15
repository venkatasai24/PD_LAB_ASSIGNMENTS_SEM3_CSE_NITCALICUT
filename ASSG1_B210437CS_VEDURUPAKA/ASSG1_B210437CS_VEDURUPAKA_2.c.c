#include<stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    int A[n],count=0;
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(-1000<=A[i] && A[i]<=1000){
            count+=1;
        }
    }
    int m;
    scanf("%d",&m);
    if(0<=n && n<=10000 && count==n && 0<m && m<=10000){
        for(i=0;i<n;i++){
            printf("%d ",A[(i+m)%n]);
        }
    }
    return 0;
}