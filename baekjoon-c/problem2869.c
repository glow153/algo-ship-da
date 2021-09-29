#include <stdio.h>
int main(void){
	int a, b, v, day=0;
	scanf("%d%d%d", &a, &b, &v);
	for(day=1;(a-b)*(day-1)+a < v;day++);
	printf("%d\n",day);
	return 0;
}