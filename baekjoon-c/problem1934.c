#include <stdio.h>
#define SWAP(x,y) x^=y^=x^=y
int GCD(int a, int b){
	if(a<b)
		SWAP(a,b);
	if(b!=0)
		return GCD(b, a%b);
	else
		return a;
}
int main(void){
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;t++){
		int a,b,g,lcm;
		scanf("%d %d",&a, &b);
		g = GCD(a,b);
		lcm = a*b/g;
		printf("%d\n",lcm);
	}
	return 0;
}