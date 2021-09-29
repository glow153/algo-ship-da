#include <stdio.h>
#include <stdlib.h>
int getMax(int* ia, int len){
	int max = ia[0];
	for(int i=1;i<len;i++)
		if(max < ia[i])
			max = ia[i];
	return max;
}
int main(void){

	unsigned long long iaSeq[101];
	int* iaInput;
	int tc;
	iaSeq[0] = 0;
	iaSeq[1] = 1;
	iaSeq[2] = 1;
	iaSeq[3] = 1;
	iaSeq[4] = 2;

	scanf("%d",&tc);
	iaInput = (int*)malloc(sizeof(int)*tc);
	for(int i=0;i<tc;i++)
		scanf("%d",&iaInput[i]);

	for(int i=5; i<=getMax(iaInput, tc); i++){
		iaSeq[i] = iaSeq[i-5] + iaSeq[i-1];
	}

	for(int i=0;i<tc;i++)
		printf("%llu\n",iaSeq[iaInput[i]]);

	free(iaInput);
	return 0;
}
