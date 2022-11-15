#include<stdio.h>
int main()
{
    char s[100];
    fgets(s,100,stdin);
    int i,length=0;
    for(i=0;s[i]!='\0';i++){
        length+=1;
    }
    int result=0;
    for(i=0;i<(length/2);i++){
        if(s[length-1-i]-s[i] == 32 || s[length-1-i]-s[i] == 0 || s[length-1-i]-s[i] == -32){
            result+=1;
        }
    }
    if(result==(length/2)){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}