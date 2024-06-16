/*
 *
 * Stack implementation using singly linked list.
 * Basic stacks operation:
 *  - Push  : add data at the front of a list.
 *  - Pop   : remove and return the value at the end of a list.
 *  - Top/peek : return the front of a stack's value withuot removing the value.
 * 
 * In this program we use tail as the front of the stack.
 *
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

void push(Node** head, Node** tail, int data){
}

int pop(Node** tail){
}

int peek(Node* tail){
}

void free_up_memory(Node** head){
	Node* node = *head;
	while(*head != NULL){
		*head = node->next;
		free(node);
		node = *head;
	}
}

int main(){
	Node* head;
	Node* tail;
	head = tail = NULL;
	push(&head, &tail, 12);
	push(&head, &tail, 1);
	push(&head, &tail, 15);
	push(&head, &tail, 4);
	push(&head, &tail, 20);
	
	free_up_memory(&head);
}
