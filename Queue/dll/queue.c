/*
 *
 * Queue implementation using doubly linked list.
 * Basic queue operation:
 * 
 * 	- Enqueue  : add element onto the queue.
 *  - Dequeue   : remove an element from the queue.
 *  - Peek : return the front of a queue's value withuot removing the value.
 *
 * In this implementation, we will make the rear as the beginning/firt element of the queue, 
 * so our enqueue operation will happen at the queue's front node.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* create_new_node(int data){
	Node* new_node = malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = new_node->prev = NULL;
	return new_node;
}

void enqueue(Node** front, Node** rear, int data){
}

int dequeue(Node** rear){	
}

int peek(Node* rear){	
}

void free_up_memory(Node** front){
	Node* node = *front;
	while(*front != NULL){
		*front = node->next;
		free(node);
		node = *front;
	}
}

int main(){
	Node* front;
	Node* rear;
	front = rear = NULL;

	enqueue(&front, &rear, 12);
	enqueue(&front, &rear, 1);
	enqueue(&front, &rear, 15);
	enqueue(&front, &rear, 4);
	enqueue(&front, &rear, 20);
	
	print_stack(front);
	printf("Peek value: %d\n", peek(rear));
	printf("Pop value: %d\n", dequeue(&rear));
	printf("Peek value after dequeue: %d\n", peek(rear));
	print_stack(front);

	free_up_memory(&front);
}
