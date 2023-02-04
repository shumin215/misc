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

int __display(NODE *temp, int (*array)[10], int *row, int *col) {
	if(temp == 0)
		return 0;

	++*row;
	__display(temp->left, array, row, col);
	array[*row][(*col)++] = temp->data;
	__display(temp->right, array, row, col);
	--*row;
}

void display(NODE *temp) {
	int row = -1;
	int col = 0;
	int a[10][10] = {0,};
	__display(temp, a, &row, &col);
	
	system("clear");
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			if(a[i][j])
				printf("%4d", a[i][j]);
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int main() {

	insert_data(1, root, LEFT);
	display(root);
	insert_data(2, root, LEFT);
	display(root);
	insert_data(3, root, RIGHT);
	display(root);
	insert_data(4, root->left, LEFT);
	display(root);
	insert_data(5, root->left, RIGHT);
	display(root);
	insert_data(6, root->right, LEFT);
	display(root);
	insert_data(7, root->right, RIGHT);
	display(root);
	return 0;
}
