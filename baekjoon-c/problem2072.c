#include <stdio.h>
#define MAX 19
typedef enum{false = 0, true}bool;
int iaaBoard[MAX+2][MAX+2] = { 0 }; //0:empty, 1:black, 2:white
int min2i(int a, int b){return (a<b)?a:b;}
int max2i(int a, int b){return (a>b)?a:b;}
bool searchW2E(int color, int i, int j){
	int min = (j<=5)?1:j-4;
	int max = (j>=15)?MAX:j+4;
	int count = 0;
	for(int c = min; c <= max; c++){
		if(iaaBoard[i][c] == color)
			count++;
		else
			count = 0;
		if(count==5 && (iaaBoard[i][c-5]!=color)
			&& (iaaBoard[i][c+1]!=color))
			return true;
	}
	return false;
}
bool searchN2S(int color, int i, int j){
	int min = (i<=5)?1:i-4;
	int max = (i>=15)?MAX:i+4;
	int count = 0;
	for(int c = min; c <= max; c++){
		if(iaaBoard[c][j] == color)
			count++;
		else
			count = 0;
		if(count==5 && (iaaBoard[c-5][j]!=color)
			&& (iaaBoard[c+1][j]!=color))
			return true;
	}
	return false;
}
bool searchNW2SE(int color, int i, int j){
	int min = min2i(i,j);
	int max = max2i(i,j);
	int minGapFrStart2Cur = (min<5)?min-1:4;
	int minGapFrCur2End = (max>MAX-5)?MAX-max:4;
	int istart = i-minGapFrStart2Cur;
	int jstart = j-minGapFrStart2Cur;
	int count = 0;
	for(int c = 0; c < minGapFrStart2Cur+minGapFrCur2End+1; c++){
		if(iaaBoard[istart+c][jstart+c] == color)
			count++;
		else
			count = 0;
		if(count==5 && (iaaBoard[istart+c-5][jstart+c-5]!=color)
			&& (iaaBoard[istart+c+1][jstart+c+1]!=color))
			return true;
	}
	return false;
}
bool searchNE2SW(int color, int i, int j){ //incompleted
	int min = min2i(i,MAX-j+1);
	int max = max2i(i,MAX-j+1);
	int minGapFrStart2Cur = (min<5)?min-1:4;
	int minGapFrCur2End = (max>MAX-5)?MAX-max:4;
	int istart = i-minGapFrStart2Cur;
	int jstart = j+minGapFrStart2Cur;
	int count = 0;
	for(int c = 0; c < minGapFrStart2Cur+minGapFrCur2End+1; c++){
		if(iaaBoard[istart+c][jstart-c] == color)
			count++;
		else
			count = 0;
		if(count==5 && (iaaBoard[istart+c-5][jstart-c+5]!=color)
			&& (iaaBoard[istart+c+1][jstart-c-1]!=color))
			return true;
	}
	return false;
}
bool scan(int i, int j){
	if(iaaBoard[i][j]!=0){
		if(searchW2E(iaaBoard[i][j], i, j)) return true;
		if(searchN2S(iaaBoard[i][j], i, j)) return true;
		if(searchNW2SE(iaaBoard[i][j], i, j)) return true;
		if(searchNE2SW(iaaBoard[i][j], i, j)) return true;
	}
	else
		return false;
}
int main(void){
	int iNum;
	int iaaHands[100][2];

	scanf("%d", &iNum);
	for (int i = 0; i < iNum; i++)
		scanf("%d %d", &iaaHands[i][0], &iaaHands[i][1]);

	for (int i = 0; i < iNum; i++){
		iaaBoard[iaaHands[i][0]][iaaHands[i][1]] = (i % 2) + 1;
		if(scan(iaaHands[i][0], iaaHands[i][1])){
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
