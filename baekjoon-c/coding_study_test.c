#include <stdio.h>
int main(void){
	int input, num, count = 0;
	scanf("%d",&input);

	for(int i = 0; i < N; i++) {
		scanf("%d",&num);
		if(num == input)
			count++;
		if(num > input && count > 0)
			break;
	}

	printf("%d\n",count);
	return 0;
}