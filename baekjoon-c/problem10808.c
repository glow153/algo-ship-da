#include <stdio.h>
int main(void){
	char str[101]={0};
	int count[26]={0};
	scanf("%s",str);
	for(int i=0;i<101;i++)
		count[str[i]-'a']++;
	for(int i=0;i<25;i++)
		printf("%d ",count[i]);
	printf("%d\n",count[25]);
	return 0;
}