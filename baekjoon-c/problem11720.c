#include <stdio.h>
int main(void){
	char s[101];
	int n, sum = 0;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++)
		sum += (int)(s[i]-'0');
	printf("%d\n",sum);
	return 0;
}