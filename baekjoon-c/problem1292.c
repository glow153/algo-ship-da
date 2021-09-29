#include <stdio.h>
int main(void){
	int start, end, sum=0;
	int idxTable[46];
	int n=0;
	for(int i=0;i<46;i++){
		n+=i;
		idxTable[i] = n;
	}

	scanf("%d %d",&start,&end);
	start--;
	end--;
	for(int i=start;i<=end;i++){
		for(int j=0;j<46;j++){
			if(idxTable[j] <= i && i < idxTable[j+1]){
				sum += (j+1);
				break;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}