#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

int length = 0;

Node* create_node(int data){
	Node* new_node = malloc(sizeof(Node));
	new_node -> data = data;
	new_node->next = new_node->prev = NULL;
	return new_node;
}

void prepend(Node** head, Node** tail, int value){
	Node* new_node = create_node(value);
	length++;
	if(*head == NULL || *tail == NULL){
		*head = *tail = new_node;
		return;
	}

	Node* node = *head;
	new_node->next = node;
	node->prev = new_node;
	*head = new_node;
}

void append(Node** head, Node** tail, int value){
	Node* new_node = create_node(value);
	length++;
	if(*head == NULL || *tail == NULL){
		*head = *tail = new_node;
		return;
	}

	Node* node = *tail;
	node->next = new_node;
	new_node->prev = node;
	*tail = new_node;
}

void remove_head(Node** head, Node** tail){
	if(*head == NULL || *tail == NULL){
		printf("-=-=-=- Trying to remove an empty list -=-=-=-\n");
		return;
	}

	if(length == 1){
		*head = *tail = NULL;
		length--;
		return;
	}
	length--;	
	Node* node = *head;
	node->next->prev = NULL;
	*head = node->next;
	free(node);
}

void remove_tail(Node** head, Node** tail){
	if(*head == NULL || *tail == NULL){
		printf("-=-=-=- Trying to remove an empty list -=-=-=-\n");
		return;
	}

	if(length == 1){
		*head = *tail = NULL;
		length--;
		return;
	}
	length--;
	Node* node = *tail;
	node->prev->next = NULL;
	*tail = node->prev;
	free(node);
}

void traverse(Node* head){
	Node* node = head;
	printf(" --- Traversing Linked list ---\n");
	while(node != NULL){
		printf("%d -> ", node->data);
		node = node -> next;
	}
	printf(" NULL\n");
}

void traverse_reverse(Node* tail){
	Node* node = tail;
	printf(" --- Traversing Linked list ---\n");
	while(node != NULL){
		printf("%d -> ", node->data);
		node = node -> prev;
	}
	printf(" NULL\n");
}

void free_all(Node* head){
	Node* node = head;
	while(node != NULL){
		Node* node_to_delete = node;
		node = node -> next;
		free(node_to_delete);
	}
}

int main(){
	Node* head;
	Node* tail;
	head = tail = NULL;
	// 56 9 77 5 10 
	prepend(&head, &tail, 77);
	append(&head, &tail, 5);
	prepend(&head, &tail, 9);
	append(&head, &tail, 10);
	prepend(&head, &tail, 56);

	traverse(head);
	remove_head(&head, &tail);
	remove_head(&head, &tail);
	traverse_reverse(tail);

	free_all(head);
}
