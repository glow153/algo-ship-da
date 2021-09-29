#include <stdio.h>
int main(void){
	int n;
	long long fib[10001];
	scanf("%d",&n);
	fib[0] = 0;
	fib[1] = 1;
	for(int i=2;i<=n;i++)
		fib[i] = fib[i-1] + fib[i-2];
	printf("%lld\n", fib[n]);
	return 0;
}