#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int main(void){
	int n;
	int in[300], dp[300];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	dp[0] = in[0];
	dp[1] = in[0] + in[1];
	dp[2] = max(in[2] + dp[0], in[2] + in[1]);
	for(int i=3;i<n;i++)
		dp[i] = max(in[i] + dp[i-2], in[i] + in[i-1] + dp[i-3]);

	printf("%d\n",dp[n-1]);
	return 0;
}