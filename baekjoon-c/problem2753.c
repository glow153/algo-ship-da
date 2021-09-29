#include <stdio.h>
typedef enum{false=0, true}bool;
bool isYoon(int year){
	if(year%400==0)
			return true;
	else if(year%4==0 && year%100!=0)
		return true;
	else
		return false;
}
int main(void){
	int y;
	scanf("%d",&y);
	printf("%d\n",isYoon(y)?1:0);
	return 0;
}