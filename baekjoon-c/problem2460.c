#include <stdio.h>
int main(void){
	int numofPassenger=0;
	int max=0;
	for(int i=0;i<10;i++){
		int out,in;
		scanf("%d %d", &out, &in);
		numofPassenger += (-out+in);
		if(max < numofPassenger)
			max = numofPassenger;
	}
	printf("%d\n",max);
	return 0;
}