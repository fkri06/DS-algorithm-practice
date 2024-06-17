/*
 *
 * Queue implementation using singly linked list.
 * Basic queue operation:
 *  - Enqueue  : add element onto the queue.
 *  - Dequeue   : remove an element from the queue.
 *  - Peek : return the front of a queue's value withuot removing the value.
 *
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* create_new_node(int data){
	Node* new_node = malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = NULL;
	return new_node;
}

void enqueue(Node** front, Node** rear, int data){
	Node* new_node = create_new_node(data);
	if(*front == NULL){
		*front = *rear = new_node;
		return;
	}
	(*rear)->next = new_node;
	*rear = new_node;
}

int dequeue(Node** front){
	if(*front != NULL){
		Node* node_to_dequeue = *front;
		int dequeue_value = node_to_dequeue->data;
		*front = node_to_dequeue->next; // fix the link
		free(node_to_dequeue); // release the memory back
		return dequeue_value;
	}
}

int peek(Node* front){
	if(front != NULL) return front->data;
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
	printf(peek(front));
	print_queue(front);
	printf(dequeue(&front));
	print_queue(front);
	printf(peek(front));
	
	free_up_memory(&front);
}
