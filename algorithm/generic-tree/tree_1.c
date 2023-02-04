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

void pre_order(NODE *temp) {
	if(temp == 0)
		return;
	printf("%d\n", temp->data);
	pre_order(temp->left);
	pre_order(temp->right);
}

void in_order(NODE *temp) {
	if(temp == 0)
		return;
	in_order(temp->left);
	printf("%d\n", temp->data);
	in_order(temp->right);
}

void post_order(NODE *temp) {
	if(temp == 0)
		return;
	post_order(temp->left);
	post_order(temp->right);
	printf("%d\n", temp->data);
}

int main() {
	insert_data(1, root, LEFT);
	insert_data(2, root, LEFT);
	insert_data(3, root, RIGHT);
	insert_data(4, root->left, LEFT);
	insert_data(5, root->left, RIGHT);
	insert_data(6, root->right, LEFT);
	insert_data(7, root->right, RIGHT);

	in_order(root);
	in_order(root);
	in_order(root);
	return 0;
}
