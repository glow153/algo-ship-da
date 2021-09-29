#include <stdio.h>
int main(){
	int narr[100000] = {0};
	int n, i, j, maxSum, maxIdxLeft, maxIdxRight, answer;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&narr[i]);

	maxSum = 0;
	maxIdxLeft = 0;
	maxIdxRight = 0;
	for (i=0;i<n;i++){
		int sum = 0;
		for (j=i;j<n;i++){
			sum += narr[j];
		}
		if (maxSum < sum){
			maxSum = sum;
			maxIdxLeft = i;
			maxIdxRight = j;
		}
	}
	answer = 0;
	for (i=maxIdxLeft;i<=maxIdxRight;i++)
		answer += narr[i];
	printf("%d\n", answer);
	return 0;
}