#include <stdio.h>
int max2i(int a, int b){return a>b?a:b;}
int main(void){
	int dp[301];
	int val[301];
	int input;
	scanf("%d",&input);
	val[0] = 0;
	for(int i=1;i<=input;i++)
		scanf("%d",&val[i]);
	dp[0] = val[0];
	dp[1] = val[1];
	dp[2] = dp[1] + val[2];
	for(int i=3;i<=input;i++)
		dp[i] = max2i(dp[i-3]+val[i-1]+val[i], dp[i-2]+val[i]);

	printf("%d\n",dp[input]);
	return 0;
}