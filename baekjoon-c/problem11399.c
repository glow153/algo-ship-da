#include <stdio.h>
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int pivot = arr[(left + right) / 2];
      int temp;
      do {
          while (arr[i] < pivot) 
		i++;
	  while (arr[j] > pivot)
		j--;
	  if (i<= j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	  }
	} while (i<= j);

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);

      if (i < right)
            quickSort(arr, i, right);
}
int main(void){
	int people[1000];
	int n, sum = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&people[i]);
	quickSort(people, 0, n-1);
	for(int i=1;i<n;i++)
		people[i] += people[i-1];
	for(int i=0;i<n;i++)
		sum += people[i];
	printf("%d",sum);
	return 0;
}