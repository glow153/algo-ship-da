#include <stdio.h>

int main(void){
	int numofInput;
	int ia[10000]={0};

	scanf("%d",&numofInput);
	for(int i=0;i<numofInput;i++){
		int n;
		scanf("%d",&n);
		ia[n-1]++;
	}

	for(int i=0;i<10000;i++){
		for(int j=0;j<ia[i];j++){
			printf("%d\n",i+1);
		}
	}
	return 0;
}