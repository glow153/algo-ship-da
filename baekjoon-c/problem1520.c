#include <stdio.h>
int row, col;
int b[500][500];
int dp[500][500];
void show(void){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++)
			printf("%d ",dp[i][j]);
		putchar('\n');
	}
}
int path(int r, int c){
	int cnt = 0;
	if(r==row-1 && c==col-1)
		return 1;
	else if(dp[r][c] != -1)
		return dp[r][c];
	else if(r>=0 && c>=0 && r<row && c<col){
		if (b[r][c] > b[r][c+1] && c+1 < col)
			cnt += path(r,c+1);
		if (b[r][c] > b[r+1][c] && r+1 < row)
			cnt += path(r+1,c);
		if (b[r][c] > b[r][c-1] && c-1 >= 0)
			cnt += path(r,c-1);
		if (b[r][c] > b[r-1][c] && r-1 >= 0)
			cnt += path(r-1,c);
	}
	dp[r][c] = cnt;
	return cnt;
}
int main(void){
	scanf("%d%d", &row, &col);
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			scanf("%d", &b[i][j]);
			dp[i][j] = -1;
		}
	}
	printf("%d\n",path(0,0));
	show();
	return 0;
}