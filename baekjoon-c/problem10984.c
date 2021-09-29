#include <stdio.h>
int main(void){
	int tc;
	scanf("%d",&tc);
	for(int t = 0; t < tc; t++){
		int a, sum = 0;
		float totalDegree = 0.0f;
		scanf("%d",&a);
		for(int i=0;i<a;i++){
			int d1;
			float d2;
			scanf("%d%f",&d1,&d2);
			sum += d1;
			totalDegree += (d1 * d2);
			//printf("%d\n",d1*d2);
		}
		totalDegree /= sum;
		printf("%d %.1f\n",sum,totalDegree);
	}
	return 0;
}