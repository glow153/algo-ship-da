#include <stdio.h>

int max2i(int a, int b){
	return (a>b)?a:b;
}
int main(void){
	int iaaInput[500][500]={0};
	int dpTable[500][501]={0};
	int iTriangleSize;

	scanf("%d",&iTriangleSize);
	for(int i=0; i<iTriangleSize; i++)
		for(int j=0; j<=i; j++)
			scanf("%d",&iaaInput[i][j]);

	for(int i=0; i<iTriangleSize; i++){	//make dp table
		for(int j=0; j<=i; j++){
			if(j==0)
				dpTable[i][j] = dpTable[i-1][j] + iaaInput[i][j];
			else if(j==i)
				dpTable[i][j] = dpTable[i-1][j-1] + iaaInput[i][j];
			else
				dpTable[i][j] = max2i(dpTable[i-1][j-1], dpTable[i-1][j])
					+ iaaInput[i][j];
		}
	}
	int max = dpTable[iTriangleSize-1][0];
	for(int i=1; i<iTriangleSize; i++){	//find maximum number
		if(max < dpTable[iTriangleSize-1][i])
			max = dpTable[iTriangleSize-1][i];
	}

	printf("%d\n",max);

	return 0;
}
