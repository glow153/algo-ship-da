#include <stdio.h>
#include <string.h>
int main(void){
	char s1[1001], s2[1001];
	scanf("%s %s", s1, s2);
	if(strlen(s1) >= strlen(s2))
		printf("go\n");
	else
		printf("no\n");
	return 0;
}