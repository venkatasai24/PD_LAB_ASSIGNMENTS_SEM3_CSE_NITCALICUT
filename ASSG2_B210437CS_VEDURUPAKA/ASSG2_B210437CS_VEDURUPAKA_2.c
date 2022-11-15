#include <stdio.h>
int main()
{
    int n,i,k,r=0;
    scanf("%d",&n);
    scanf("%d",&k);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int num;
    scanf("%d",&num);
    int count=0;
    i=0;
    int tr=0;
    for(i=0;i<n;i++){
        if(a[i]>=-1000 && a[i]<=1000){
            tr+=1;
        }
    }
    if(1<=n && n<=1000 && 1<=k && k<=n && tr==n){
        while(r<=n){
            for(i=r;i<k+r;i++){
                if(num==a[i]){
                    count+=1;
                    break;
                }
            }
            r+=k;
        }
        printf("%d",count);
    }
    return 0;
}
