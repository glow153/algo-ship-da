#include <stdio.h>
int main(void){
	int num, max, count = 0;
	int student[6][2]={0};
	scanf("%d %d",&num,&max);
	for(int i=0;i<num;i++){
		int s,g;
		scanf("%d %d",&s,&g);
		student[g-1][s]++;
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<2;j++){
			if(student[i][j] > 0){
				if(student[i][j] > max){
					count += student[i][j] / max;
					if(student[i][j] % max)
						count++;
				}
				else
					count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}