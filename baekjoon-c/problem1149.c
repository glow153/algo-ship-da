#include <stdio.h>
int min2i(int a, int b){return a<b?a:b;}
int main(void){
	int input;
	int iaDP[1000][3];
	scanf("%d",&input);
	scanf("%d %d %d",&iaDP[0][0], &iaDP[0][1], &iaDP[0][2]);
	for(int i=1;i<input;i++){
		int r, g, b;
		scanf("%d %d %d",&r,&g,&b);
		iaDP[i][0] = min2i(iaDP[i-1][1]+r, iaDP[i-1][2]+r);
		iaDP[i][1] = min2i(iaDP[i-1][0]+g, iaDP[i-1][2]+g);
		iaDP[i][2] = min2i(iaDP[i-1][0]+b, iaDP[i-1][1]+b);
	}
	printf("%d",min2i(min2i(iaDP[input-1][0], iaDP[input-1][1]), iaDP[input-1][2]));
}