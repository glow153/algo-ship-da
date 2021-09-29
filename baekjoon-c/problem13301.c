#include <stdio.h>
int main(void){
	long long perimeter[80];
	int input;
	perimeter[0] = 4;
	perimeter[1] = 6;
	scanf("%d",&input);
	for(int i=2;i<input;i++)
		perimeter[i] = perimeter[i-1] + perimeter[i-2];
	printf("%lld\n",perimeter[input-1]);
	return 0;
}