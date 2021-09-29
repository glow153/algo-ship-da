#include <stdio.h>
int max2(int a, int b){return a>b?a:b;}
int max3(int a, int b, int c){
	int m = max2(a,b);
	return max2(m,c);
}
int main(void){
	int n;
	int in[10000], dp[10000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	dp[0] = in[0];
	dp[1] = in[1] + dp[0];
	dp[2] = max3(in[2] + dp[0], in[2] + in[1], dp[1]);
	for(int i=3;i<n;i++)
		dp[i] = max3(dp[i-1], in[i] + dp[i-2], in[i] + in[i-1] + dp[i-3]);
	printf("%d\n",dp[n-1]);
	return 0;
}