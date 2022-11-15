#include<stdio.h>
typedef unsigned long long int ulli;
ulli POWER(ulli a,int e){
    ulli result=0;
    while(a!=0){
        ulli s=1;
        ulli remain=a%10;
        for(int i=1;i<=e;i++){
            s*=remain;
        }
        result+=s;
        a/=10;
    }
    return result;
}
int main(){
    ulli number;
    scanf("%llu",&number);
    int power;
    scanf("%d",&power);
    ulli sum=POWER(number,power);
    printf("%llu",sum);
    return 0;
}