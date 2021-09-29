#include <stdio.h>
int ctoi(char c){
	if(c==0)
		return -1;
	return (int)c - (int)'0';
}
int main(void){
	int iaCntNum[10] = {0};
	char sInput[11];
	scanf("%s",sInput);
	for(int i=0;i<10;i++)
		iaCntNum[ctoi(sInput[i])]++;
	for(int i=9;i>=0;i--)
		for(int j=0;j<iaCntNum[i];j++)
			printf("%d",i);
	return 0;
}