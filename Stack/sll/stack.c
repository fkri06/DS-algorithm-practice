/*
 *
 * Stack implementation using singly linked list.
 * Basic stacks operation:
 *  - Push  : add data at the front of a list.
 *  - Pop   : remove and return the value at the end of a list.
 *  - Top/peek : return the front of a stack's value withuot removing the value.
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

void push(Node** head, int data){
	Node* new_node = create_new_node(data);
	new_node -> next = *head;
	*head = new_node;
}

int pop(Node** head){
	if(*head == NULL) return -1;
	Node* node_to_pop = *head;
	int pop = node_to_pop -> data;
	*head = node_to_pop -> next;
	free(node_to_pop);
	return pop;
}

int peek(Node* head){

}

int main(){
}
