#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int translate(char* ca){
	int num = 0;
	int exp[3] = {1,2,4};
	for(int i=0;i<3;i++){
		if(ca[2-i]=='1'){
			num += exp[i];
		}
	}
	return num;
}
int main(void){
	char strInput[1000001]={0};
	int idxLast;
	int len;
	int* oct;
	int octLen;
	scanf("%s",&strInput);
	len = strlen(strInput);
	idxLast = len - 1;
	octLen = ((len-1)/3)+1;
	oct = (int*)malloc(sizeof(int)*octLen);

	for(int i=0;i<octLen;i++){
		char caTranslator[4]={0};
		for(int j=0;j<3;j++){
			int idxTmp = idxLast - i*3 - j;
			if(idxTmp>=0)
				caTranslator[2-j] = strInput[idxTmp];
			else
				caTranslator[2-j] = '0';
		}
		//printf("segment %d : %s\n",octLen-i-1,caTranslator);
		oct[octLen-i-1] = translate(caTranslator);
	}

	for(int i=0;i<octLen;i++){
		printf("%d",oct[i]);
	}
	putchar('\n');
	free(oct);
	return 0;
}
