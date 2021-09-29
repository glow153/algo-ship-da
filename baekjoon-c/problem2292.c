#include <stdio.h>
int main(void){
	int input;
	int lastEnd = 1, end;
	scanf("%d",&input);
	if(input == 1){
		printf("1\n");
		return 0;
	}
	for(int i=2;;i++){
		end = lastEnd + 6*(i-1);
		if(end>=input){
			printf("%d\n",i);
			break;
		}
		else{
			int tmp = lastEnd;
			lastEnd = end;
			end = tmp;
		}
	}
	return 0;
}