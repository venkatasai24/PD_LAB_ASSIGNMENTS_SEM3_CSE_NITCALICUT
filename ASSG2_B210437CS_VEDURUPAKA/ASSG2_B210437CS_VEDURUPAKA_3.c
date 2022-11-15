#include <stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int tr=0;
    for(i=0;i<n;i++){
        if(-1000<=a[i] && a[i]<=1000){
            tr+=1;
        }
    }
    if(1<=n && n<=1000 && tr==n){
        int max=a[0];
        for(i=0;i<n;i++){
            if(a[i]>max){
                max=a[i];
            }
        }
        int max2=-1001;
        for(i=0;i<n;i++){
            if(a[i]!=max){
                if(a[i]>max2){
                    max2=a[i];
                }
            }
        }
        for(i=0;i<n;i++){
            if(a[i]==max2){
                for(j=i;j<(n-1);j++){
                    a[j]=a[j+1];
                }
                n=n-1;
            }
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
    return 0;
}
