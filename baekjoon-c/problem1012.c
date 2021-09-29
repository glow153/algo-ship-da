#include <stdio.h>
typedef enum _bool{
	false, true
}bool;

bool baaField[50][50] = {false};
bool baaVisited[50][50] = {false};

bool dfs(int i, int j, int r, int c){
	if(i>=r || j>=c || i<0 || j<0)
		return false;
	//printf("%d, %d visited.\t",i,j);
	baaVisited[i][j] = true;
	if(baaField[i][j]){ //배추가 있으면
		//printf("there is cabbage! :)\n");
		if(!baaVisited[i+1][j])
			dfs(i+1, j, r, c);
		if(!baaVisited[i][j+1])
			dfs(i, j+1, r, c);
		if(!baaVisited[i-1][j])
			dfs(i-1, j, r, c);
		if(!baaVisited[i][j-1])
			dfs(i, j-1, r, c);
		return true;
	}
	else{ //배추가 없으면
		//printf("there is no cabbage. :(\n");
		return false;
	}
}

void resetField(){
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			baaField[i][j] = false;
			baaVisited[i][j] = false;
		}
	}
}


int main(void){
	int tc;
	int row, col, cabbage;
	scanf("%d",&tc);
	for(int t=0;t<tc;t++){
		int count = 0;
		resetField();
		scanf("%d %d %d", &row, &col, &cabbage);
		for(int i=0;i<cabbage;i++){
			int x, y;
			scanf("%d %d", &x, &y);
			baaField[x][y] = true;
		}
		for(int j=0;j<col;j++){
			for(int i=0;i<row;i++){
				if(!baaVisited[i][j]){
				//방문하지 않았으면 탐색시작
					if(dfs(i,j,row,col)){
						count++;
						//printf("cabbage count : %d\n",count);
					}
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
