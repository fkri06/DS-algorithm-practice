/*
 * Heap implementation using doubly linked list.
 * Basic Heap operation:
 * 	- Insert -> insert an element to a heap. Insertion
 * 	  in a Heap always start from the bottom/end of list/array.
 *
 * 	- Remove -> remove the root element from a heap. Deletion
 * 	  in a Heap always delete the root node, and then from there
 * 	  fix the heap arrangements.
*/

#include<stdio.h>

int heap_length = 0;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int find_parent(int index){
	return (index - 1) / 2;
}

int find_left_child(int index){
}

int find_right_child(int index){
}

void insert(int index, int* array){
	int parent_index = find_parent(index);
	if(index == 0) return;
	
	int parent_value = array[parent_index];
	int value = array[index];

	if(parent_value < value){
		swap(&array[parent_index], &array[index]);
		insert(parent_index,  array);
	}
}

int delete(int index){
}

int main(){

	int input_data_length;
	printf("How many value you want to insert to the heap? ");
	scanf("%d", &input_data_length);
	
	int array[input_data_length];
	int value;

	for(int i = 0; i < input_data_length; i++){
		printf("Input value to a heap: ");
		scanf("%d", &value);
		
		array[heap_length] = value;
		insert(heap_length, array);
		heap_length++;
	}

	printf("heap length: %d\n", heap_length);
	for(int i = 0; i < input_data_length; i++){
		printf("%d\n", array[i]);
	}

}
