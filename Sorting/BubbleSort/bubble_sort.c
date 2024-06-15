#include<stdio.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int* array, int len){
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len - i - 1; j++){
			if(array[j] > array[j + 1]){
				swap(&array[j], &array[j + 1]);
			}
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
	bubble_sort(array, len);
	print_array(array, len);
}
