#include <stdio.h>
int ctoi(char c){
	return c-'0';
}
int main(void){
	int input;
	scanf("%d",&input);
	for(int i=0;i<input;i++){
		char sInput[4];
		while(getchar()==0);
		scanf("%s",sInput);
		printf("%d\n",ctoi(sInput[0])+ctoi(sInput[2]));
	}
	return 0;
}