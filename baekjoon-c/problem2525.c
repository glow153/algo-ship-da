#include <stdio.h>
int main(void){
	int hour, minute;
	int dur;
	scanf("%d %d", &hour, &minute);
	scanf("%d", &dur);
	minute+=dur;
	hour+=minute/60;
	minute%=60;
	hour%=24;
	printf("%d %d\n",hour,minute);
	return 0;
}