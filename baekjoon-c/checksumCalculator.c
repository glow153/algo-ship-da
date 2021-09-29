#include <stdio.h>
#include <string.h>
#define DEBUG
typedef unsigned char BYTE;

BYTE getChksum(int pkt){
	BYTE ret = 0;
	for(int i=0;i<3;i++){
		ret ^= (0xFF & (BYTE)(pkt >> i*8));
#ifdef DEBUG
		printf("%d : %X %X %X\n",i+1,
			(BYTE)(pkt >> i*8),0xFF & (BYTE)(pkt >> i*8),ret);
#endif
	}
	return ret;
}
int main(void){
	printf("**** Check Sum Calculator ****\n");
	printf("**** 	made by Jake	 ****\n");
	while(1){
		long iInput;
		printf("input : ");
		scanf("%X",&iInput);
		printf("chksum : %X\n",getChksum(iInput));
	}
	return 0;
}