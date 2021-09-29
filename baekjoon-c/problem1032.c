#include <stdio.h>
#include <string.h>
int main(void){
	int input;
	char sInput[50][51];
	char sOutput[51];
	int len;
	scanf("%d",&input);
	for(int i=0;i<input;i++){
		scanf("%s",sInput[i]);
	}
	len = strlen(sInput[0]);
	for(int j=0;j<len;j++){
		int cnt = 1;
		char cTmp = sInput[0][j];
		for(int i=1;i<input;i++){
			if(cTmp == sInput[i][j])
				cnt++;
		}
		if(cnt==input)
			sOutput[j] = cTmp;
		else
			sOutput[j] = '?';
	}
	sOutput[len] = 0;
	printf("%s\n",sOutput);
	return 0;
}