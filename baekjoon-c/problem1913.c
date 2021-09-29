#include <stdio.h>
#include <stdlib.h>
int searchR, searchC;
void makeSnail(int** snail, int input){
	int num = 1;
	snail[input/2][input/2] = num++;
	for(int i=1;i<=input/2;i++){
		for(int j=0;j<i*2;j++)
			snail[input/2-i][input/2+j-(i-1)] = num++;
		for(int j=0;j<i*2;j++)
			snail[input/2+j-(i-1)][input/2+i] = num++;
		for(int j=0;j<i*2;j++)
			snail[input/2+i][input/2-j+(i-1)] = num++;
		for(int j=0;j<i*2;j++)
			snail[input/2-j+(i-1)][input/2-i] = num++;
	}
}
void search(int** snail, int size, int num){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(snail[i][j] == num){
				searchR = i+1;
				searchC = j+1;
				return;
			}
		}
	}
}
int main(void){
	int input, selnum;
	int** iaaSnail;
	scanf("%d %d", &input, &selnum);
	iaaSnail = (int**)malloc(sizeof(int*)*input);
	iaaSnail[0] = (int*)malloc(sizeof(int)*input*input);
	for(int i=1;i<input;i++)
		iaaSnail[i] = iaaSnail[i-1] + input;

	makeSnail(iaaSnail, input);
	search(iaaSnail, input, selnum);
	for(int i=0;i<input;i++){
		for(int j=0;j<input;j++){
			printf("%d ",iaaSnail[i][j]);
		}
		putchar('\n');
	}
	printf("%d %d\n", searchR, searchC);

	free(iaaSnail[0]);
	free(iaaSnail);
	return 0;
}