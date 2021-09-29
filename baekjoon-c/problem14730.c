#include <stdio.h>
int main(){
    int t;
    int sum=0;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        sum+=a*b;
    }
    printf("%d\n",sum);
    return 0;
}