#include <stdio.h>
int main()
{
    char s[1000];
    fgets(s,1000,stdin);
    int freq[26]={0};
    int i,j,correct=0,length=0;
    for(i=0;s[i]!='\0';i++){
        length+=1;
        if(s[i]>=97 && s[i]<=122){
            correct+=1;
        }
    }
    if(correct==length){
       for(i=0;i<length;i++){
           freq[s[i]-97]+=1;
        }
       int p=1;
       for(i=0;i<26;i++){
          if(freq[i]!=0){
              p*=freq[i];
            }
        }
       printf("%d",p);
    }
    return 0;
}
