#include <stdio.h>
int min2i(int a, int b){
	return (a<b)?a:b;
}
int min3i(int a, int b, int c){
	int d = min2i(b,c);
	return (a<d)?a:d;
}
int main(void){
	int dp[1000000];
	int input;
	scanf("%d",&input);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i=3;i<=input;i++){
		dp[i] = min3i(dp[i/3],dp[i/2],dp[i]-1);
		printf("dp[%d] = %d",i,dp[i]);
	}
	printf("%d",dp[input]);
	return 0;
}