#include <stdio.h>
#include <string.h>
int main(void){
	int stack[10000]={0};
	int idxTop = -1;
	int input;
	scanf("%d",&input);
	for(int i=0;i<input;i++){
		char cmd[6]={0};
		scanf("%s",cmd);
		if(!strcmp(cmd,"push")){
			int num;
			scanf("%d", &num);
			stack[++idxTop] = num;
		}else if(!strcmp(cmd,"pop")){
			if(idxTop<0)
				printf("-1\n");
			else{
				printf("%d\n",stack[idxTop]);
				stack[idxTop--] = 0;
			}
		}else if(!strcmp(cmd,"top")){
			if(idxTop<0)
				printf("-1\n");
			else
				printf("%d\n",stack[idxTop]);
		}else if(!strcmp(cmd,"size")){
			printf("%d\n",idxTop+1);
		}else if(!strcmp(cmd,"empty")){
			printf("%d\n",(idxTop==-1)?1:0);
		}
	}
	return 0;
}