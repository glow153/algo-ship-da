#include <stdio.h>
int main(void){
	int num, i, last, count = 0, maxCount = 0;
	int bAsc = -1;
	scanf("%d",&num);
	scanf("%d",&last);
	for(int t=1;t<num;t++){
		scanf("%d",&i);
		printf("%d: %d %d %d\n",t, last, i, count);
		if(last < i){
			if(bAsc == 0){
				bAsc = 1;
				maxCount = (maxCount<count)?count:maxCount;
				count = 1;
			}
			else
				count++;
		}
		else if(last > i){
			if(bAsc == 1){
				bAsc = 0;
				maxCount = (maxCount<count)?count:maxCount;
				count = 1;
			}
			else
				count++;
		}
		else{
			int accum = 2;
			t++;
			for(;;t++){
				scanf("%d",&i);
				printf("%d: %d %d %d\n",t, last, i, count);
				if(last < i){
					if(bAsc == 0){
						bAsc = 1;
						count = accum;
					}else{
						count += accum;
					}
					break;
				}
				else if(last > i){
					if(bAsc == 1){
						bAsc = 0;
						count = accum;
					}else{
						count += accum;
					}
					break;
				}
				else{
					accum++;
					continue;
				}
			}
		}
		last = i;
	}
	printf("%d\n",maxCount);
	return 0;
}