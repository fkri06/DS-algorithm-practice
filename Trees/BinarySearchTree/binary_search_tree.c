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

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* create_node(int data, Node* left, Node* right){
	Node* new_node = malloc(sizeof(Node));
	new_node -> data = data;
	new_node->left = left
	new_node->right = right;
	return new_node;
}

void insert(Node** root, int value){
}

void delete(Node** root){
}

int search(Node* root){
}

void preorder(Node* root){
}

void inorder(Node* root){
}

void postorder(Node* root){
}

void levelorder(Node* root){
}

void free_all(Node* root){
}

int main(){
}
