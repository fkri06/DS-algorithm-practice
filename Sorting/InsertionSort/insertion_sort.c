#include<stdio.h>

void insertion_sort(int* array, int len){
	for(int index = 1; index < len; index++){
		int temp_value = array[index];
		int position = index - 1;

		while(position >= 0 && array[position] > temp_value){
			array[position + 1] = array[position];
			position--;
		}
		array[position + 1] = temp_value;
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
	insertion_sort(array, len);
	print_array(array, len);
}
