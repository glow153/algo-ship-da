#include <stdio.h>
#include <string.h>
int ctoi(char c){
	if('0'<=c && c<='9')
		return (int)c-(int)'0';
	else
		return -1;
}
int getLength(char* ca, int max){
	static int idx = 0;
	int count = 0;
	for(;idx<max;idx++){
		if(ca[idx] == '('){
			int m = ctoi(ca[(idx++)-1]);
			count += (m * getLength(ca,max) - 1);
		}
		else if(ca[idx] == ')')
			return count;
		else
			count++;
	}
	return count;
}

int main(void){
	char sInput[51];
	scanf("%s",sInput);
	printf("%d\n",getLength(sInput, strlen(sInput)));
	return 0;
}
