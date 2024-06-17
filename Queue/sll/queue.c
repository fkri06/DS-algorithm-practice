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
}

int dequeue(Node** front){
}

int peek(Node* front){
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
	front = rear = NULL
}
