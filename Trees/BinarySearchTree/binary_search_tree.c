/*
 *
 * Binary Search Tree implementation using doubly linked list.
 * Basic BST operation:
 *
 *	- Insert -> insert an element to a tree.
 *	- Delete -> remove an element from a tree.
 *	- Search -> searching an element in a tree.
 *	- Traversal:
 *		* Preorder
 *		* Inorder
 *		* Postorder
 *		* Level Order
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

Node* create_node(int value, Node* left, Node* right){
	Node* new_node = malloc(sizeof(Node));
	new_node -> value = value;
	new_node->left = left;
	new_node->right = right;
	return new_node;
}

void insert(Node** root, int value){
	if(value < (*root)->value){
		if((*root)->left == NULL){
			Node* new_node = create_node(value, NULL, NULL);
			(*root)->left = new_node;
		} else{
			insert(&(*root)->left, value);
		}
	} else if(value > (*root)->value){
		if((*root)->right == NULL){
			Node* new_node = create_node(value, NULL, NULL);
			(*root)->right = new_node;
		} else{
			insert(&(*root)->right, value);
		}
	}
}

Node* finding_node_successor(Node* node, Node* node_to_delete){
	if(node->left){
		node->left = finding_node_successor(node->left, node_to_delete);
		return node;
	} else{
		node_to_delete->value = node->value;
		return node->right;
	}
}

Node* delete(Node** root, int value_to_delete){
	if(*root == NULL) return *root;
	if(value_to_delete < (*root)->value){
		(*root)->left = delete(&(*root)->left, value_to_delete);
	} else if(value_to_delete > (*root)->value){ 
		(*root)->right = delete(&(*root)->right, value_to_delete);
	} else{
		if((*root)->left == NULL && (*root)->right){
			free(*root);
			*root = NULL;
		} if((*root)->left == NULL){
			return (*root)->right;
		} else if((*root)->right == NULL){
			return (*root)->left;
		} else{
			(*root)->right = finding_node_successor((*root)->right, *root);
		}
	}
	return *root;
}

int search(Node* root, int value_to_search){
	if(root == NULL) return 0;
	if(value_to_search == root->value){
		return 1;
	} else if(value_to_search < root->value){
		return search(root->left, value_to_search);
	} else{
		return search(root->right, value_to_search);
	}
}

/* Depth first traversal*/
void preorder(Node* root){
	if(root == NULL) return;
	printf("%d ", root->value);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ", root->value);
	inorder(root->right);
}

void postorder(Node* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);	
	printf("%d ", root->value);
}

/* Breadth first traversal */
void levelorder(Node* root){
	Queue* front;
	Queue* rear;
	Queue* mark_front;
	mark_front = front = rear = NULL;
	enqueue(&mark_front, &front, &rear, root);
	
	printf("Levelorder Traversal\n");
	while(front != NULL){ // while the queue is not empty
		Node* pop_node = dequeue(&front); // this can cause memory leak
		printf("%d ", pop_node->value);
		if(pop_node->left != NULL) {
			enqueue(&mark_front, &front, &rear, pop_node->left);
		}
		if(pop_node->right != NULL) {
			enqueue(&mark_front, &front, &rear, pop_node->right);
		}
	}
	printf("\n");
	free_up_q(&mark_front);
}

void free_all(Node* root){
	if(root == NULL){
		return;
	}
	free_all(root->left);
	free_all(root->right);
	free(root);
	root = NULL;
}

int main(){

	Node* node10 = create_node(57, NULL, NULL);
	Node* node11 = create_node(80, NULL, NULL);

	Node* node8 = create_node(20, NULL, NULL);
	Node* node9 = create_node(42, NULL, NULL);	

	Node* node6 = create_node(55, NULL, node10);
	Node* node7 = create_node(70, NULL, node11);	

	Node* node4 = create_node(30, node8, NULL);
	Node* node5 = create_node(45, node9, NULL);
	
	Node* node2 = create_node(40, node4, node5);
	Node* node3 = create_node(60, node6, node7);

	Node* root = create_node(50, node2, node3);

	// traversal
	printf("preorder Traversal\n");
	preorder(root);
	printf("\n");

	insert(&root, 35);
	insert(&root, 90);

	printf("\nInorder Traversal\n");
	inorder(root);
	printf("\n");

	printf("SEARCH: %d\n", search(root, 100));
	printf("SEARCH: %d\n", search(root, 35));
	
	root = delete(&root, 50);
	printf("Current root: %d\n", root->value);	
	
	printf("\nPostorder Traversal\n");
	postorder(root);
	printf("\n");

	levelorder(root);
	free_all(root);
}
