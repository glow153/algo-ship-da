#include <stdio.h>
int main(void){
	char sInput[101];
	char sOutput[101]={0};
	gets(sInput);
	int i=0;
	while(sInput[i]!=0){
		if('A' <= sInput[i] && sInput[i] <= 'Z'){
			sOutput[i] = (sInput[i] - 'A' + 13) % 26 + 'A';
		}
		else if('a' <= sInput[i] && sInput[i] <= 'z'){
			sOutput[i] = (sInput[i] - 'a' + 13) % 26 + 'a';
		}
		else{
			sOutput[i] = sInput[i];
		}
		i++;
	}
	printf("%s\n",sOutput);
	return 0;
}
