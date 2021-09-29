#include <stdio.h>
#include <string.h>
int isGroup(char* s, int len){
    for(int i=0;i<len;i++){
        char c=s[i];
        for(int j=i+1;j<len-1;j++){
            if(s[j]!=c&&s[j+1]==c){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int n,r=0;
    scanf("%d",&n);
    for(int t=0;t<n;t++){
        char s[100];
        int b[100];
        int len,k=1;
        scanf("%s",s);
        len = strlen(s);
        r+=isGroup(s,len);
    }
    printf("%d\n",r);
    return 0;
}