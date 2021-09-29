#include <stdio.h>
int main(void){
	int max=0, idx;
	for(int i=0;i<9;i++){
		int n;
		scanf("%d",&n);
		if(max < n){
			max = n;
			idx = i;
		}
	}
	printf("%d\n%d\n", max, idx+1);
	return 0;
}