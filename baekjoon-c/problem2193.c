#include <stdio.h>
int main(void){
	unsigned long long fib[92];
	int input;
	scanf("%d",&input);
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;
	for(int i=3;i<=input;i++)
		fib[i] = fib[i-2]+fib[i-1];
	printf("%llu\n",fib[input]);
	return 0;
}