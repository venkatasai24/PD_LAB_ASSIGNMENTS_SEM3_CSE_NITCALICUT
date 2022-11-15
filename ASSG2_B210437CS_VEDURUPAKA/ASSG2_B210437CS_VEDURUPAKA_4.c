#include <stdio.h>
int binarysearch(int a[],int l,int r,int t){
    int mid=(l+r)/2;
    if(l<=r){
        if(t==a[mid]){
            return mid;
        }
        else if(t<a[mid]){
            return binarysearch(a,l,mid-1,t);
        }
        else{
            return binarysearch(a,mid+1,r,t);
        }
    }
    else{
        return -1;
    }
}
int main()
{
    int i,n,t;
    scanf("%d",&n);
    scanf("%d",&t);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int tr=0;
    for(i=0;i<n;i++){
        if(a[i]>=-1000 && a[i]<=1000){
            tr+=1;
        }
    }
    if(1<=n && n<=1000 && t>=-1000 && t<=1000 && tr==n){
        int index=binarysearch(a,0,n-1,t);
        printf("%d\n",index);
        if(index<0){
            printf("-1");
        }
        else{
            int count=0;
            for(i=index;i<n;i++){
                if(a[i]>a[index]){
                    count+=1;
                    printf("%d ",i);
                }
            }
            if(count==0){
                printf("-1");
            }
        }
    }
    return 0;
}
