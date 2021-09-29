#include <stdio.h>
int main(void){
	int num=1;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0;i<k;i++)
		num*=n-i;
	for(int i=0;i<k;i++)
		num/=k-i;
	printf("%d\n",num);
	return 0;
}