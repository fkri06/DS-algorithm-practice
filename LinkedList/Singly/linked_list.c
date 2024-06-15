#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

int length = 0;

Node* create_node(int data){
	Node* new_node = malloc(sizeof(Node));
	new_node -> data = data;
	return new_node;
}

void insert(Node** head, int value){
	Node* new_node = create_node(value);
	new_node->next = *head;
	*head = new_node;
	length++;
}

void delete(Node** head){
	if(*head == NULL) {
		printf("-=-=-=-=- Trying to delete NULL lists -=-=-=-=-\n");
	}
	Node* node_to_delete = *head;
	*head = node_to_delete -> next;
	free(node_to_delete);
	length--;
}

void insert_at(Node** head, int value, int index){
	if(index < 0 || index > length){
		printf("-=-=-=-=- Trying to add value at overlapping index -=-=-=-=-\n");
		return;
	}

	length++;
	Node* new_node = create_node(value);
	if(index == 0){
		new_node -> next = *head;
		*head = new_node;
		return;
	}

	Node* node = *head;
	for(int i = 0; i < index - 1; i++){
		node = node -> next;
	}

	new_node -> next = node -> next;
	node -> next = new_node;
}

void delete_at(Node** head, int index){
	if(index < 0 || index >= length || *head == NULL){
		printf("-=-=-=-=- Trying to remove value at overlapping index or an empty list -=-=-=-=-\n");
		return;
	}

	Node* node = *head;
	length--;
	if(index == 0){
		*head = node -> next;
		free(node);
		return;
	}

	for(int i = 0; i < index - 1; i++){
		node = node->next;
	}

	Node* node_to_delete = node->next;
	node->next = node_to_delete->next;
	free(node_to_delete);
}

Node* reversed_recurse(Node** head, Node* node){
	if(*head == NULL) return NULL;
	if(node -> next == NULL){
		*head = node;
		return node;
	}
	Node* next_node = reversed_recurse(head, node->next);
	node->next = NULL;
	next_node->next = node;
	return node;
}

void reversed_iterative(Node** head){
	if(length <= 1 || *head == NULL){
		printf("-=-=-=-=- list empty or has only one node -=-=-=-=-\n");
		return;
	}

	Node* prev = NULL;
	Node* current = *head;
	Node* next = current->next;

	while(current->next != NULL){
		current->next = prev;
		prev = current;
		current = next;
		next = current->next;
	}

	current->next = prev;
	*head = current;
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

void traverse_recurse(Node* head){
	if (head == NULL) return;
	traverse_recurse(head->next);
	printf("%d -> ", head->data);
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
	Node* head = NULL;
	insert(&head, 77);
	insert(&head, 5);
	insert(&head, 9);
	insert(&head, 10);
	insert(&head, 56);
	
	traverse(head);
	//delete(&head);
	// printf("List's length = %d\n", length);
	// insert_at(&head, 69, 2);
	// printf("List's length = %d\n", length);
	
	delete_at(&head, 2);
	traverse(head);
	reversed_iterative(&head);
	traverse(head);
	reversed_recurse(&head, head);
	traverse(head);
	traverse_recurse(head); printf(" NULL\n");

	free_all(head);
}
