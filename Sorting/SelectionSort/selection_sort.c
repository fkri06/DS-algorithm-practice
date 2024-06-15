#include<stdio.h>

void swap(int* a, int* b){
	int xor = (*a) ^ (*b);
	*a = xor ^ (*a);
	*b = xor ^ (*b);
}

void selection_sort(int* array, int len){
	for(int i = 0; i < len; i++){
		int min_index_sofar = i;
		for(int j = i + 1; j < len; j++){
			if(array[j] < array[min_index_sofar]){
				min_index_sofar = j;
			}
		}
		if(i != min_index_sofar){
			swap(&array[i], &array[min_index_sofar]);
		}
	}
}

void print_array(int* array, int len){
	for(int i = 0; i < len; i++){
		printf("%d - ", array[i]);
	}
	printf("\n");
}

int main(){
	int array[] = {5, 3, 1, 7, 6, 9, 10, 2, 4, 8};
	int len = sizeof(array) / sizeof(array[0]);

	printf("Unsorted array: \n");
	print_array(array, len);

	printf("Sorted array: \n");
	selection_sort(array, len);
	print_array(array, len);
}
