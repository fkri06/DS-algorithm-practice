#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value;
	struct Node* left;
	struct Node* right;
} Node;

typedef struct Queue {
	Node* node;
	struct Queue* next;
} Queue;

Queue* create_new_node(Node* node){
	Queue* new_node = malloc(sizeof(Queue));
	new_node -> node = node;
	new_node -> next = NULL;
	return new_node;
}

void enqueue(Queue** mark_front, Queue** front, Queue** rear, Node* node){
	Queue* new_node = create_new_node(node);
	if(*front == NULL){
		*mark_front = *front = *rear = new_node;
		return;
	}
	(*rear)->next = new_node;
	*rear = new_node;
}

Node* dequeue(Queue** front){	
	Queue* node_to_dequeue = *front;
	Node* dequeue_value = node_to_dequeue->node;
	*front = node_to_dequeue->next; // fix the link
	return dequeue_value;	
}

void free_up_q(Queue** mark_front){
	Queue* node;
	while(*mark_front != NULL){
		node = *mark_front;
		*mark_front = (*mark_front)->next;
		free(node);
		node = NULL;
	}
}
