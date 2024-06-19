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
#define MAX 100

int data[MAX];
int length = 0;

int find_parent(int index){
}

int find_left_child(int index){
}

int find_right_child(int index){
}

void insert(int index){
}

int delete(int index){
}

int main(){
	insert(50);
	insert(40);
	insert(30);
	insert(22);
	insert(10);
	insert(20);
	insert(25);
}
