#include <stdio.h>
int paper[100][100] = {0};
int xMax=0, yMax=0;
void fillRect(int x1, int y1, int x2, int y2){
	for(int i=yMax-1-y2;i<=yMax-1-y1;i++){
		for(int j=x1;j<x2;j++){
			paper[i][j] = 1;
		}
	}
}

void print(){
	for(int j=0;j<xMax;j++){
		for(int i=0;i<yMax;i++)
			printf("%d ",paper[i][j]);
		putchar('\n');
	}
}

int main(void){
	int tc;
	scanf("%d %d %d", &xMax, &yMax, &tc);
	for(int t=0;t<tc;t++){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		fillRect(x1, y1, x2, y2);
	}
	print();
	return 0;
}
