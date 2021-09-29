#include <stdio.h>
int main(void) {
    int dp[31] = { 0 };
    int n;
    scanf("%d", &n);
    if (n % 2) {
        printf("0\n");
        return 0;
    }
    dp[0]=1;
    dp[2]=3;
    for(int i=4;i<=n;i+=2){
        dp[i]=dp[2]*dp[i-2];
        for(int j=4;j<=i;j+=2)
            dp[i]+=2*dp[i-j];
    }

    printf("%d\n",dp[n]);
    return 0;
}