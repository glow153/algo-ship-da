#include <stdio.h>
#include <math.h>
typedef enum _bool{false = 0, true}bool;
bool IsSquare(unsigned int num) {
  unsigned int temp;
  switch (num & 0x0f) {
  case 0:
  case 1:
  case 4:
  case 9:
    temp = (unsigned int)(sqrt((double)num)+0.5);
    return temp*temp == num;
     
  default:
    return false;
  }
}
int main(void){
	int a,b,min,sum=0;
	bool exist = false;
	scanf("%d %d",&a, &b);
	for(int i=a;i<=b;i++){
		if(IsSquare(i)){
			if(!exist){
				min = i;
				exist = true;
			}
			sum+=i;
		}
	}
	if(!exist)
		printf("-1\n");
	else
		printf("%d\n%d\n",sum,min);
	return 0;
}