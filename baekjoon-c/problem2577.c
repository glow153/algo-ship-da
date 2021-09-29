#include <stdio.h>
#include <math.h>
#define MAXPOS 9
int main(void){
	int a,b,c;
	int product;
	int iaDigit[10] = {0};
	int len;
	scanf("%d %d %d",&a,&b,&c);
	product = a*b*c;

	for(int i=6;i<MAXPOS;i++){
		if((int)pow(10,i) <= product &&
			product < (int)pow(10,i+1))
			len = i+1;
	}
	for(int i=0;i<len;i++){
		int d = (product / (int)pow(10,i)) % 10;
		iaDigit[d]++;
	}
	
	for(int i=0;i<10;i++)
		printf("%d\n",iaDigit[i]);
	return 0;
}