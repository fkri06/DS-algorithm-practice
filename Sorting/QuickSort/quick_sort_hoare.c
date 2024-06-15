/*
 * quick sort implementation in C using Hoare partition scheme.
 *
 * */

#include<stdio.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int low, int high, int* array){
	int pivot_index = high;
	int pivot = array[pivot_index];
	high--;
	
	while(1){
		while(array[low] < pivot) low++;
		while(array[high] > pivot) high--;

		if(low >= high){
			break;
		} else{
			swap(&array[low], &array[high]);
			low++;
		}
	}
	swap(&array[pivot_index], &array[low]);
	return low;
}

void quick_sort(int low, int high, int* array){
	if(high - low <= 0){
		return;
	}
	int partition_index = partition(low, high, array);
	quick_sort(low, partition_index - 1, array);
	quick_sort(partition_index + 1, high, array);
}

void print_array(int len, int* array){
	for(int i = 0; i < len; i++){
		printf("%d - ", array[i]);
	}
	printf("\n");
}

int main(){
	int array[] = {5, 3, 1, 7, 6, 9, 10, 2, 4, 8};
	int len = sizeof(array) / sizeof(array[0]);
	
	printf("Unsorted array: \n");
	print_array(len, array);

	printf("Unsorted array: \n");
	quick_sort(0, len - 1, array);
	print_array(len, array);
}
