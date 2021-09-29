#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 11
int getMax(int* ia, int len){
	int max = ia[0];
	for(int i=1;i<len;i++){
		if(max < ia[i])
			max = ia[i];
	}
	return max;
}
int main(void){
	long long dp[MAXLEN];
	int tc;
	int* iaInput;
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	scanf("%d",&tc);
	iaInput = (int*)malloc(sizeof(int)*tc);
	for(int i=0;i<tc;i++)
		scanf("%d",&iaInput[i]);

	for(int i=3;i<MAXLEN;i++)//generate DP table
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	for(int i=0;i<tc;i++)
		printf("%d\n",dp[iaInput[i]-1]);
	return 0;
}