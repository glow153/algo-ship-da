#include <stdio.h>
#include <stdlib.h>
void q_sort(int numbers[], int left, int right) {
	int pivot, l_hold, r_hold;
	l_hold = left;
	r_hold = right;
	pivot = numbers[left];
	while (left < right) {
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right) {
			numbers[left] = numbers[right];
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right) {
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		q_sort(numbers, left, pivot - 1);
	if (right > pivot)
		q_sort(numbers, pivot + 1, right);
}
int main(void){
	int num;
	int* ia;
	scanf("%d", &num);
	ia = (int*)malloc(sizeof(int)*num);
	for(int i=0;i<num;i++)
		scanf("%d",&ia[i]);

	q_sort(ia, 0, num-1);

	for(int i=0;i<num;i++)
		printf("%d\n",ia[i]);
	free(ia);
	return 0;
}