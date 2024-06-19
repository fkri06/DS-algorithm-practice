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
	return (index * 2) + 1;
}

int find_right_child(int index){
	return (index * 2) + 2;
}

void heap_up(int index, int* array){
	int parent_index = find_parent(index);
	if (index == 0) return;

	int parent_value = array[parent_index];
	int value = array[index];

	if(parent_value < value){
		swap(&array[parent_index], &array[index]);
		heap_up(parent_index,  array);
	}
}

void heap_down(int index, int* array){
	int left_index = find_left_child(index);
	int right_index = find_right_child(index);

	if(index >= heap_length || left_index >= heap_length){
		return;
	}

	int left_value = array[left_index];
	int right_value = array[right_index];
	int value = array[index];

	if(left_value > right_value && left_value > value){
		swap(&array[left_index], &array[index]);
		heap_down(left_index, array);
	} else if(right_value > left_value && right_value > value){
		swap(&array[right_index], &array[index]);
		heap_down(right_index, array);	
	}

}

void insert(int index, int value, int* array){
	array[heap_length] = value;
	heap_up(index, array);
	heap_length++;
}

int delete(int index, int array[]){
	if(heap_length == 0) return -1;
	
	int last_value_out = array[heap_length - 1];
	heap_length--;
	
	if(heap_length == 1){
		return last_value_out;
	}

	int remove_root_value = array[0];
	array[0] = last_value_out;
	heap_down(index, array);
	return remove_root_value;
}

void print_heap(int* array, int length){
	printf("heap length: %d\n", length);
	for(int i = 0; i < length; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
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
		
		insert(heap_length, value, array);
	}

	print_heap(array, heap_length);
	printf("Delete root: %d\n", delete(0, array));
	print_heap(array, heap_length);
}
