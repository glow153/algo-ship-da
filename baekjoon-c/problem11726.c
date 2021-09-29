#include <stdio.h>
int main(){
	int dp[1001]={0};
	int i, n;
	dp[0] = 1;
	dp[1] = 1;
	scanf("%d", &n);
	for(i=2;i<=n;i++)
		dp[i] = ((dp[i-1] + dp[i-2]) % 10007);
	printf("%d\n", dp[n]);
	return 0;
}