#include <stdio.h>
#define MAX 1001
typedef enum _bool {
	false, true
}bool;
int main(void){
	int input;
	int iaInput[100];
	int count=0;
	bool baChe[MAX]={0};
	int iaPrime[500] = {0};

	scanf("%d",&input);
	for(int i=0;i<input;i++)
		scanf("%d",&iaInput[i]);

	for(int i=2;i<MAX;i++){	//initiate array
		baChe[i] = true;
	}

	for(int i=2;i<=1000;i++){	//make Eratostenes' che
		if(baChe[i]){
			for(int j=2;i*j<=1000;j++)
				baChe[i*j] = false;
		}
	}
	for(int i=0;i<input;i++)
		if(baChe[iaInput[i]])
			count++;
	printf("%d\n",count);
	return 0;
}