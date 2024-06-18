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
	int value;
	struct Node* left;
	struct Node* right;
} Node;

Node* create_node(int value, Node* left, Node* right){
	Node* new_node = malloc(sizeof(Node));
	new_node -> value = value;
	new_node->left = left;
	new_node->right = right;
	return new_node;
}

void insert(Node** root, int value){
}

void delete(Node** root){
}

int search(Node* root){
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
}

void free_all(Node* root){
}

int main(){

	Node* node10 = create_node(57, NULL, NULL);
	Node* node11 = create_node(80, NULL, NULL);
	
	Node* node8 = create_node(20, NULL, NULL);
	Node* node9 = create_node(42, NULL, NULL);	

	Node* node6 = create_node(55, NULL, node10);
	Node* node7 = create_node(70, NULL, node11);	

	Node* node4 = create_node(30, node8, NULL);
	Node* node5 = create_node(40, node9, NULL);
	
	Node* node2 = create_node(40, node4, node5);
	Node* node3 = create_node(60, node6, node7);

	Node* root = create_node(50, node2, node3);
	
	// traversal
	printf("preorder Traversal\n");
	preorder(root);

	printf("\nInorder Traversal\n");
	inorder(root);
	
	printf("\nPostorder Traversal\n");
	postorder(root);
}
