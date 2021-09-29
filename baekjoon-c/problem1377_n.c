#include <stdio.h>
void printArr(int* a, int n){
	for(int i=1;i<=n;i++)
		printf("%2d",a[i]);
	printf("\n");
}
int main(void){
	int N = 5;
	int A[5+1] = {0,5,4,1,3,2};
	int i,j,temp;
	int change;
	for (i=1; i<=N; i++){
	    change = 0;
	    printf("i : %d\n",i);
	    for (j=1; j<=N-i; j++){
	        if(A[j] > A[j+1]){
	            change = 1;
	            temp = A[j];
	            A[j] = A[j+1];
	            A[j+1] = temp;
	            printArr(A,N);
	        }
		}
		if (change == 0) {
		        break;
		}
	}
	printArr(A,N);
	printf("\n%d\n",i);
	return 0;
}