#include <stdio.h>
int main(void){
	int iaaInput[300][300];
	int n,m,k;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&iaaInput[i][j]);
	scanf("%d",&k);
	for(int tc=0;tc<k;tc++){
		int _i,_j,_x,_y;
		int sum = 0;
		scanf("%d %d %d %d",&_i,&_j,&_x,&_y);
		for(int i=_i;i<=_x;i++){
			for(int j=_j;j<=_y;j++){
				sum += iaaInput[i-1][j-1];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
