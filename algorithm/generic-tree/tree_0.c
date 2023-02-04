#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} NODE;

NODE *root;

typedef enum {LEFT, RIGHT} FLAG;
void insert_data(int data, NODE *s, FLAG flag) {
	NODE *temp;
	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;

	if(root == 0) {
		root = temp;
		return;
	}

	if(flag == LEFT) s->left = temp;
	else if(flag == RIGHT) s->right = temp;
}

int main() {
	insert_data(1, root, LEFT);
	insert_data(2, root, LEFT);
	insert_data(3, root, RIGHT);
	insert_data(4, root->left, LEFT);
	insert_data(5, root->left, RIGHT);
	insert_data(6, root->right, LEFT);
	insert_data(7, root->right, RIGHT);
	return 0;
}
