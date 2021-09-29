#include <stdio.h>
#include <math.h>
long long fib(int num){
    return (long long)((double)(pow((((double)1+sqrt(5))/2),num)-pow((((double)1-sqrt(5))/2),num))/sqrt(5));
}
int main(void){
    int n;
    scanf("%d",&n);
    printf("%lld\n", fib(n));
    return 0;
}