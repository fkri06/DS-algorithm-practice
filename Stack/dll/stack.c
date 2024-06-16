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
	Node* new_node = create_new_node(data);
	if(*tail == NULL){
		*head = *tail = new_node;
		return;
	}
	new_node->prev = *tail;
	(*tail)->next = new_node;
	*tail = new_node;
}

int pop(Node** tail){
	if(*tail != NULL){
		Node* node_to_pop = *tail;
		int pop_value = node_to_pop -> data;
		*tail = node_to_pop -> prev;
		(*tail)->next = NULL;
		free(node_to_pop);
		return pop_value;
	}
}

int peek(Node* tail){
	if(tail != NULL){
		return tail->data;
	}
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
	print_stack(head);
	printf("Peek value: %d\n", peek(tail));
	printf("Pop value: %d\n", pop(&tail));
	printf("Peek value after pop: %d\n", peek(tail));
	print_stack(head);
	free_up_memory(&head);
}
