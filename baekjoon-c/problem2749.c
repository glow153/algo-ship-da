#include <stdio.h>
#define mod 1000000
#define period (15*(mod/10))
int fibo_p[period];
int main(void){
	long long input;
	fibo_p[0] = 0;
	fibo_p[1] = 1;
	scanf("%lld", &input);
	for(int i=2;i<period;i++)
		fibo_p[i] = (fibo_p[i-1] + fibo_p[i-2]) % mod;
	printf("%d\n",fibo_p[input%period]);
	return 0;
}