#include <stdio.h>
int main(void){
	int tc, rpm = 1, cwccw = 0;
	scanf("%d",&tc);	
	for(int t=0;t<tc;t++){
		int r1, r2, c;
		scanf("%d%d%d", &r1, &r2, &c);
		rpm = (rpm / r1) * r2;
		if(c)
			cwccw = 1 - cwccw;
	}
	printf("%d %d\n",cwccw,rpm);
	return 0;
}