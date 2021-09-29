#include <stdio.h>
int comb[30][30] = {0};
int min2i(int a, int b){return (a<b)?a:b;}
void generateBinCoef(int startN, int n){
	for(int i = startN; i <= n; i++){
		comb[i][0] = 1;
		for(int j = 1; j <= n; j++)
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	}
}
int main(void){
	int tc, maxN=1, maxR=1;
	comb[0][0] = 1;
	scanf("%d",&tc);
	for(int t=0;t<tc;t++){
		int n, r;
		scanf("%d %d",&r, &n);
		r = min2i(r, n-r);
		if( maxN == 1 )
			generateBinCoef(1,n);
		else if( maxN > n )
			generateBinCoef(maxN+1,n);
		printf("%d\n",comb[n][r]);
	}
	return 0;
}