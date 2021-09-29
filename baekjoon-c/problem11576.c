#include <stdio.h>
#include <math.h>
int getDigit(int s, int b){
    int i=0;
    while(1){
        if(pow(b,i)>s)
            return i;
        else
            i++;
    }
}
int main(void) {
    int a, b, tc, s=0, d;
    scanf("%d%d%d",&a,&b,&tc);
    for(int i=1;i<=tc;i++){
        int n;
        scanf("%d",&n);
        s += n*pow(a,tc-i);
    }
    d=getDigit(s, b);

    printf("s_10 val = %d, digit(s_%d) = %d\n",s,b,d);

    for(int i=d-1;i>=0;i--){
        int z=pow(b,i);
        int t=s/z;
        printf("%d/%d=",s,z);
        printf("%d ",t);
        if(t==0)
            continue;
        s%=(t*z);
    }
    return 0;
}