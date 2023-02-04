#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} NODE;

NODE *root;


typedef enum {LEFT, RIGHT} FLAG;
void insert_data(int data) {
	NODE *temp;
	NODE **p = &root;
	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;

	while(*p) {
		if((*p)->data > data)
			p = &(*p)->left;
		else if((*p)->data < data)
			p = &(*p)->right;
		else
			return;
	}
	*p = temp;
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
	int a[] = {4, 2, 1, 3, 6, 5, 7};
	int i;
	display(root);
	for(i=0; i<7; i++) {
		insert_data(a[i]);
		display(root);
	}

	return 0;
}
