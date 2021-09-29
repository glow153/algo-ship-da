#include <stdio.h>
void copyMtx(char** caa, int srcStartIdx, int dstStartIdx, int size){
	for(int i = srcStartIdx; i < srcStartIdx + size; i++)
		for(int j = srcStartIdx; j < srcStartIdx + size; j++)
			caa[dstStartIdx + i][dstStartIdx + j] = caa[i][j];
}

int main(void){
	char caa[2187][2187] = 0;

	caa[0][0] = '*';

	for(int i=1;i<=9;i*=3)
		copyMtx(caa, 0, 1, 1);

	for(int i=0;caa[i][0]!=0;i++){
		for(int j=0;caa[i][j]!=0;i++)
			printf("%c",caa[i][j]);
		printf("\n");
	}
	return 0;
}
